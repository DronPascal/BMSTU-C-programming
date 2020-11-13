#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <ctime> 

struct node
{
	char symb[10] = { '\0' };
	float num;
	node *left=nullptr, *right=nullptr;
};

struct variable
{
	char name[10] = { '\0' };
	float value;
	variable *n;
};

bool equation_check(char *equation);	//проверка уравнения на наличие ошибок в записи

void cut_the_bracket(char *equation, int &begin, int &end); //удаление внешних скобочек, если они есть (изменяя left и right)
node* make_tree(char *equation, int left = 0, int right = 0); //рекурсивная функция создания дерева 
void tree_pruning(node **root);

float get_variable(node *root, variable **variables = nullptr, bool rnd = 0); //получение значения переменной (значения переменных и их названия хранятся в списке)
float calculate_tree(node *root, variable **variables = nullptr, bool *error = nullptr);	//рекурсивная функцифя расчета дерева

void print_tree(node *root, int level = 0);	//форматный вывод дерева на экран
void preOrderTravers(node* root);	//прямой обход
void inOrderTravers(node* root);	//симметричный обход
void postOrderTravers(node* root);	//обратный обход

void delete_tree(node **root);	//удаление дерева
void delete_variables(variable **variables);	//удаление списка переменных


int main()
{
	setlocale(0, "russian");
	srand(time(NULL));
	node *root=nullptr;
	variable *variables = nullptr;
	bool calc_error = 0, has_var = 0;
	char equation[50];
	float res;
	char cmd[20];
	int key, key2;
	//ввод
	do {
		printf("Введите:\n	1 Ввод формулы с клавиатуры.\n	2 Использование формулы своего варианта (12).\n	3 Выход из программы.\n");
		do {
			printf("Введите код команды: ");
			scanf("%s", &cmd);
			key = atoi(cmd);
			switch (key)
			{
			case 1:
				do {
					printf("\nВведите уравнение: ");
					scanf("%s", &equation);
				} while (equation_check(equation));	//проверка уравнения

				break;
			case 2:
				strcpy(equation, "(2*(m-3))*(3-2*(n+2))");
				printf("\nУравнение: %s\n", equation);
				equation_check(equation);	//проверка уравнения
				break;
			case 3:
				break;
			default:
				printf("Некорректный код команды.\n");
			}
		} while (key != 1 && key != 2 && key != 3);

		if (key != 3)
		{
			//построение дерева
			root = make_tree(equation);
			//упрощение дерева
			tree_pruning(&root);
			//вывод дерева
			printf("\nВывод прямым/симметричным/обратным обходом:\n");
			preOrderTravers(root); printf("\n");
			inOrderTravers(root);  printf("\n");
			postOrderTravers(root);  printf("\n");
			printf("\nВывод в виде дерева:\n");
			print_tree(root);
			//расчет дерева
			res = calculate_tree(root, &variables, &calc_error);
			if (!calc_error)
				printf("\nResult = %4.2f\n\n", res);

			//удаление динамических структур данных
			delete_tree(&root);
			delete_variables(&variables);
		}
	} while (key!=3);
}

bool equation_check(char *equation)	//проверка уравнения на наличие ошибок в записи
{
	int bracket = 0;
	bool error = 0, signs_in_raw = 0, bad_symbols = 0, bad_brackets = 0, bad_operator = 0, bad_variable = 0;
	int i;
	for (i = 0; i < strlen(equation); i++)
	{
		if (!(strchr("*/+-(),0123456789", equation[i])))
			if (!isalpha(equation[i]))
				bad_symbols = 1;
			else if (i == 1)	
				if ((strchr("0123456789.", equation[i - 1])))
					bad_variable = 1;
			else if (i >= 2)
				if ((strchr("0123456789.", equation[i - 1])) && strchr("(*/+-", equation[i - 2]))
					bad_variable = 1;
		if (equation[i] == '(')
		{
			bracket++;
			if (strchr("*/", equation[i + 1]))
				bad_operator = 1;
			if (!(strchr("*/+-(", equation[i - 1])) && i!=0)
				bad_brackets = 1;
		}
		else if (equation[i] == ')')
		{
			bracket--;
			if (strchr("*/+-", equation[i - 1]))
				bad_operator = 1;
			if (equation[i+1] == '(')
				bad_brackets = 1;
		}
		if (strchr("*/+-", equation[i]))
			if (strchr("*/+-", equation[i + 1]))
				signs_in_raw = 1;
	}
	if (strchr("*/+-", equation[i-1]))
		bad_operator = 1;

	if (bad_symbols)	
	{
		printf("	Ошибка: Использованы недопустимые символы!\n");
		error = 1;
	}
	if (strstr(equation, "/0"))
	{
		printf("	Ошибка: Обнаружена явная попытка деления на 0!\n");
		error = 1;
	}
	if (bracket)	
	{
		printf("	Ошибка: Неправильно расставлены скобочки!\n");
		error = 1;
	}
	if (bad_brackets)
	{
		printf("	Ошибка: Отсутствует оператор перед открывающейся скобочкой!\n");
		error = 1;
	}
	if (bad_variable)
	{
		printf("	Ошибка: Название переменной не может начинаться с цифры!\n");
		error = 1;
	}
	if (signs_in_raw)	
	{
		printf("	Ошибка: Больше одного оператора подряд!\n");
		error = 1;
	}
	if (bad_operator)
	{
		printf("	Ошибка: Недопустимое расположение оператора!\n");
		error = 1;
	}
	return error;
}

void cut_the_bracket(char *equation, int &begin, int &end)	//удаление внешних скобочек, если они есть (изменяя left и right)
{
	int n = 0, k;
	bool stop = 0;
	do {
		if (equation[begin+n] == '(' && equation[end-n] == ')')	//если выражение в скобках, то проверить внутреннее выражение на корректность
		{
			k = 0;
			for (int i = begin + n + 1; i <= end - n - 1; i++)	//проверка количества открывающих и закрывающих скобочек внутри
			{
				if (equation[i] == '(') k++;
				else if (equation[i] == ')') k--;
				if (k < 0)	//если закрывающих скобочек стало больше, чем открывающих, то есть повод прекратить менять границы
					stop = 1;
			}
			if (k == 0 && stop == 0) n++;	//если выражение корректно, то сузить границы выражения
		}
		else k = 1;
	} while (k == 0 && stop == 0);	//выход после нахождения кол-ва лишних скобок
	begin = begin + n;
	end = end - n;
}
node* make_tree(char *equation, int left, int right)	//рекурсивная функция создания дерева 
{
	int cur, bracket=0, k=-1, pr_key=0;
	static int lvl = 0;
	static bool right_init = 0;
	if (lvl == 0 && right_init==0)	//при первом вызове инициализация правой границы и удаление лишних скобок (изменяя left и right)
	{
		right = strlen(equation)-1;
		cut_the_bracket(equation, left, right);
		
	}
	cur = right + 1;	//поиск операторов 0-ого уровня скобочек в уравнении обходом справа
	do {
		cur--;
		if (equation[cur] == ')') bracket++;
		else if (equation[cur] == '(')
		{
			bracket--;
			if (bracket == 0 && cur != left) cur--;
		}
		if (bracket == 0)
		{
			if (strchr("+-", equation[cur]))
			{
				k = cur;
				pr_key = 1;
			}
			else if (strchr("*/", equation[cur]) && pr_key == 0)
				k = cur;
		}	
	} while (pr_key!=1 && cur > left + 1);	//выход если найден подходящий оператор или встречен конец уравнения
	
	node *new_node = new node;	
	new_node->left = nullptr;
	new_node->right = nullptr;

	if (left>right)
		new_node->num = 0;
	else if (k==-1 && pr_key==0)	//если не найден оператор или перед оператором (
	{
		if (isalpha(equation[left]))	//если найдена переменная
		{
			for (int i = left; i <= right; i++)
				new_node->symb[i - left] = equation[i];
			new_node->symb[right - left + 1] = '\0';
		}
		else	//копирование записи числа и преобразование во float (-5.4 -> float || 5 -> float)
		{
			char num[10];
			for (int i = left; i <= right; i++)
				num[i - left] = equation[i];
			new_node->num = atof(num);
		}	
	}
	else
	{
		new_node->symb[0] = equation[k];
		new_node->symb[1] = '\0';
		
		int l_right = k - 1, r_left = k + 1;
		cut_the_bracket(equation, left, l_right);
		cut_the_bracket(equation, r_left, right);

		lvl++;
		new_node->left = make_tree(equation, left, l_right);
		new_node->right = make_tree(equation, r_left, right);
		lvl--;
	}
	if (right_init == 0 && lvl==0)
		right_init = 1;
	if (right_init && lvl == 0)
		right_init = 0;
	return new_node;
}

void tree_pruning(node **root)
{
	if (*root)
	{
		tree_pruning(&(*root)->left);
		tree_pruning(&(*root)->right);
		if ((*root)->symb[0] && strchr("+-", (*root)->symb[0]))
		{
			if ((*root)->left->symb[0] == '\0' && (*root)->right->symb[0] == '\0')
			{
				if ((*root)->left->num == 0 || (*root)->right->num == 0)
				{
					(*root)->num = calculate_tree(*root);
					(*root)->symb[0] = '\0';
					delete[](*root)->left;
					delete[](*root)->right;
					(*root)->left = (*root)->right = nullptr;
				}
			}
		}
	}
}

float get_variable(node *root, variable **variables, bool rnd)	//возврат значения переменной из списка переменных
{											//или получение значения новой и добавление ее в список 
	float var;
	variable *cur_var = nullptr;
	if (variables)
		cur_var = *variables;
	if (cur_var)
	{
		bool exit = 0;
		do {
			if (strcmp(cur_var->name, root->symb) == 0)
			{
				var = cur_var->value;
				exit = 1;
			}
			else cur_var = cur_var->n;
		} while (cur_var && exit==0);
		
		if (exit == 0)
		{
			cur_var = *variables;
			while (cur_var->n)
				cur_var = cur_var->n;
			variable *new_var = new variable;
			cur_var->n = new_var;
			strcpy(new_var->name, root->symb);
			if (rnd)
			{
				var = (double)(rand()) / RAND_MAX * 30 - 15;
				int z = var / 0.1;
				var = z * 0.1;
				printf("%s = %3.1f\n", root->symb, var);
			}
			else
			{
				printf("Введите переменную %s: ", root->symb);
				scanf("%f", &var);
			}
			new_var->value = var;
			new_var->n = nullptr;
		}
	}
	else
	{
		*variables = new variable;
		strcpy((*variables)->name, root->symb);
		if (rnd)
		{
			var = (double)(rand()) / RAND_MAX * 30 - 15;
			int z = var / 0.1;
			var = z * 0.1;
			printf("%s = %3.1f\n", root->symb, var);
		}
		else
		{
			printf("Введите переменную %s: ", root->symb);
			scanf("%f", &var);
		}
		(*variables)->value = var;
		(*variables)->n = nullptr;
	}
	return var;
}
float calculate_tree(node *root, variable **variables, bool *error)	//рекурсивная функцифя расчета дерева
{
	static int lvl = 0, passed=0, rnd = -1;
	float a, b, c;
	if (root->left)
	{
		lvl++;
		a = calculate_tree(root->left, variables, error);
	}
	if (root->right)
	{
		lvl--;
		b = calculate_tree(root->right, variables, error);
	}
	if (!(root->left || root->right))
		if (root->symb[0] && !(strchr("*/+-", root->symb[0])))
		{
			if (rnd == -1)
			{
				char cmd[10];
				int key;
				printf("\nВведите:\n	1 Ввод значений переменных с клавиатуры.\n	2 Использовать случайные значения для переменных.\n");
				do {
					printf("Введите код команды: ");
					scanf("%s", &cmd);
					key = atoi(cmd);
					switch (key)
					{
					case 1:
						rnd = 0;
						break;
					case 2:
						rnd = 1;
						break;
					default:
						printf("Некорректный код команды.\n");
					}
				} while (key != 1 && key != 2);
			}
			c = get_variable(root, variables, rnd);
		}
		else
			c = root->num;
	else if (strchr("*/+-", (root->symb[0])))
		switch (root->symb[0]) 
		{
			case '+': c = a + b; break;
			case '-': c = a - b; break;
			case '*': c = a * b; break;
			case '/': 
			{
				if (b == 0)
				{
					printf("Обнаружена попытка деления на 0!\n\n");
					*error = 1;
					exit;
				}
				c = a / b;
				break;
			}
		}
	if (passed == 0 && lvl == 0)
		passed = 1;
	if (passed && lvl == 0)
	{
		rnd = -1;
		passed = 0;
	}
	return c;
}

void print_tree(node *root, int level)	//форматный вывод дерева на экран
{
	if (root)
	{
		print_tree(root->right, level + 1);
		for (int i = 0; i < level; i++) printf("    ");
		if (root->symb[0])
			printf("%s\n", root->symb);
		else
			printf("%2.1f\n", root->num);
		print_tree(root->left, level + 1);
	}
	else if (level == 0) printf("\nДерево пусто\n");
}

void preOrderTravers(node* root) 
{
	if (root) 
	{
		if (root->symb[0])
			printf("%s ", root->symb);
		else
			printf("%2.1f ", root->num);
		preOrderTravers(root->left);
		preOrderTravers(root->right);
	}
}
void inOrderTravers(node* root) 
{
	if (root) 
	{
		inOrderTravers(root->left);
		if (root->symb[0])
			printf("%s ", root->symb);
		else
			printf("%2.1f ", root->num);
		inOrderTravers(root->right);
	}
}
void postOrderTravers(node* root)
{
	if (root) 
	{
		postOrderTravers(root->left);
		postOrderTravers(root->right);
		if (root->symb[0])
			printf("%s ", root->symb);
		else
			printf("%2.1f ", root->num);
	}
}

void delete_tree(node **root)	//удаление дерева
{
	if (*root)
	{
		delete_tree(&(*root)->left);
		delete_tree(&(*root)->right);
		delete *root;
	}
}
void delete_variables(variable **variables)	//удаление списка переменных
{
	variable *buf = *variables;
	while (buf)
	{
		*variables = (*variables)->n;
		delete buf;
		buf = *variables;
	}
}