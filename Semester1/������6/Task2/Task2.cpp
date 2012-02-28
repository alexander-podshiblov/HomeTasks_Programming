#include "stdafx.h"

struct Node
{
	char operation;
	int value;
	Node *left;
	Node *right;
};

struct Stack
{
	Node *from;
	int operand;
	Stack *next;
};

void add(Stack *head, Node *from, int operand)
{
	Stack *tmp = new Stack;
	tmp->from = from;
	tmp->operand = operand;
	tmp->next = head->next;
	head->next = tmp;
}

void del(Stack *head)
{
	Stack *tmp = head->next;
	head->next = tmp->next;
	delete tmp;
}

Node *create(char operation, int value)
{
	Node *tmp = new Node;
	tmp->operation = operation;
	tmp->value = value;
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
}

void print(Node *tmp)
{
	if ((tmp->left == NULL) && (tmp->right == NULL))
	{
		printf("%i ", tmp->value);
	}
	else 
	{
		if (tmp->left != NULL)
		{
			if ((tmp->left->left != NULL) && (tmp->left->right != NULL))
				printf("( ");
			print(tmp->left);
			if ((tmp->left->left != NULL) && (tmp->left->right != NULL))
				printf(") ");
		}
		printf("%c ", tmp->operation);
		if (tmp->right != NULL)
		{
			if ((tmp->right->left != NULL) && (tmp->right->right != NULL))
				printf("( ");
			print(tmp->right);
			if ((tmp->right->left != NULL) && (tmp->right->right != NULL))
				printf(") ");
		}
	}
}

void delChild(Node *t)
{
	delete t->left;
	delete t->right;
	t->left = NULL;
	t->right = NULL;
}

void calc(Node *t)
{
	if ((t->left->left == NULL) && (t->right->left == NULL))
	{
		if (t->operation == '+')
		{
			t->value = t->left->value + t->right->value;
			delChild(t);
		}
		else if (t->operation == '-')
		{
			t->value = t->left->value - t->right->value;
			delChild(t);
		}
		else if (t->operation == '*')
		{
			t->value = t->left->value * t->right->value;
			delChild(t);
		}
		else if (t->operation == '/')
		{
			t->value = t->left->value / t->right->value;
			delChild(t);
		}
	}
	else
	{
		if (t->left->left != NULL)
			calc(t->left);
		if (t->right->left != NULL)
			calc(t->right);
		calc(t);
	}

}

int main()
{
	Stack *head = new Stack;
	head->next = NULL;
	
	FILE *f = fopen("input.txt", "r");
	char c = 0;
	int brackets = 0;
		
	c = fgetc(f);
	brackets++;
	c = fgetc(f);
	Node *t = create(c, 0);
	add(head, t, 1);
	c = fgetc(f);

	while(brackets != 0)
	{
		c = fgetc(f);
		if (c != ' ')
		{//////////////////////////////
			if (c == '(')
			{
				c = fgetc(f);
				if (head->next->operand == 1)
				{
					Node *tmp = create(c, 0);
					head->next->from->left = tmp;
					head->next->operand = 2;
					add(head, tmp, 1);
				}
				else if (head->next->operand == 2)
				{
					Node *tmp = create(c, 0);
					head->next->from->right = tmp;
					head->next->operand = 0;
					add(head, tmp, 1);
				}
				brackets++;
			}
			else if (c == ')')
			{
				del(head);
				brackets--;
			}
			else
			{
				ungetc(c, f);
				if (head->next->operand == 1)
				{
					int value = 0;
					fscanf(f, "%i", &value);
					Node *tmp = create(0, value);
					head->next->from->left = tmp;
					head->next->operand = 2;
				}
				else if (head->next->operand == 2)
				{
					int value = 0;
					fscanf(f, "%i", &value);
					Node *tmp = create(0, value);
					head->next->from->right = tmp;
					head->next->operand = 0;
				}
			}
		}/////////////////////////////
	}
	fclose(f);
	
	print(t);

	calc(t);

	printf("= %i\n", t->value);
	
	
	scanf("%*");
	delete t;
	return 0;
}