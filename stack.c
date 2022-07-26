
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

struct Stack {
	int top;
	int capacity;
	int* array;
};

struct Stack* create_Stack(int capacity)
{
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
	stack->capacity = capacity;
	stack->top = -1;
	stack->array = (int*)malloc(stack->capacity * sizeof(int));
	return stack;
}

int is_Full(struct Stack* stack)
{
	return stack->top == stack->capacity - 1;
}

int is_Empty(struct Stack* stack)
{
	return stack->top == -1;
}

void push(struct Stack* stack, int item)
{
	if (is_Full(stack))
		return;
	stack->array[++stack->top] = item;
	printf("%d is pushed to the stack.\n", item);
}

void push_char(struct Stack* stack, int item)
{
	if (is_Full(stack))
		return;
	stack->array[++stack->top] = item;
	printf("%c is pushed to the stack.\n", item);
}

int pop(struct Stack* stack)
{
	if (is_Empty(stack))
		return 1;
	return stack->array[stack->top--];
}

int peek(struct Stack* stack)
{
	if (is_Empty(stack))
		return 1;
	return stack->array[stack->top];
}


int isPalindrome(struct Stack * stack)
{    
     int flag = 0;
     struct Stack *s1 = create_Stack(100);
     char str[1000];
     printf("Enter the string:\t");
     gets(str);
     for (int i = 0; i < (strlen(str) / 2); i++)
     {
          push_char(s1 , str[i]);
     }
     if (strlen(str) % 2 != 0)
     {
          for (int i = (strlen(str) / 2) + 1; i < strlen(str); i++)
          {
               if (str[i] == pop(s1))
               {
                    flag = 1;
               }
               else
               {
                    flag = 0;
                    break;
               }
          }
     }
     else
     {
          for (int i = (strlen(str) / 2); i < strlen(str); i++)
          {
               if (str[i] == pop(s1))
               {
                    flag = 1;
               }
               else
               {
                    flag = 0;
                    break;
               }
          }
     }
     if (flag == 1)
     {
          printf("String is palindrome \n");
     }
     else
     {
          printf("String is not palindrome \n");
     }
}


int is_Operand(char ch)
{
	return (ch >= 'a' && ch <= 'z') ||
		(ch >= 'A' && ch <= 'Z');
}


int precedence(char ch)
{
	switch (ch)
	{
	case '+':
	case '-':
		return 1;

	case '*':
	case '/':
		return 2;

	case '^':
		return 3;
	}
	return -1;
}


int infixToPostfix(char* exp)
{
	int i, k;

	struct Stack* stack = create_Stack(strlen(exp));
	if(!stack)
		return -1 ;
     printf("Stack created successfully\n");
	for (i = 0, k = -1; exp[i]; ++i)
	{
		

		if (is_Operand(exp[i]))
			exp[++k] = exp[i];
		

		else if (exp[i] == '(')
			push_char(stack, exp[i]);
		
		else if (exp[i] == ')')
		{
			while (!is_Empty(stack) && peek(stack) != '(')
				exp[++k] = pop(stack);
			if (!is_Empty(stack) && peek(stack) != '(')
				return -1; // invalid expression			
			else
				pop(stack);
		}
		else
		{
			while (!is_Empty(stack) &&
				precedence(exp[i]) <= precedence(peek(stack)))
				exp[++k] = pop(stack);
			push_char(stack, exp[i]);
		}

	}


	while (!is_Empty(stack))
		exp[++k] = pop(stack );

	exp[++k] = '\0';
	printf( "%s\n", exp );
}



void is_Balanced(struct Stack * stack)
{
     char exp[MAX];
     int count=0;
     int i = 0;
     stack->top = -1;
     printf("\nEnter the Expression : ");
     scanf("%s", exp);
     for(i = 0;i < strlen(exp);i++)
     {
          if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
          {
               push_char(stack, exp[i]);
               count++;
               continue;
          }
          else if(exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
          {
               if(exp[i] == ')')
               {
                    if(stack->array[stack->top] == '(')
                    {
                         pop(stack); 
                    }
                    else
                    {
                         printf("\nTHE EXPRESSION IS UNBALANCED\n");
                         break;
                    }
               }
               if(exp[i] == ']')
               {
                    if(stack->array[stack->top] == '[')
                    {
                         pop(stack);
                    }
                    else
                    {
                         printf("\nTHE EXPRESSION IS UNBALANCED\n");
                         break;
                    }
               }
               if(exp[i] == '}')
               {
                    if(stack->array[stack->top] == '{')
                    {
                         pop(stack); 
                    }
                    else
                    {
                         printf("\nTHE EXPRESSION IS UNBALANCED\n");
                         break;
                    }
               }
          }
     }
     if(stack->top == -1)
     {
          printf("\nTHE EXPRESSION IS BALANCED\n"); 
          printf("The no.of balanced paranthesis are %d", count);
     }
}



int main()
{    
     printf("\n================Question 1===============================\n");
     char str;
	struct Stack* stack = create_Stack(100);
     isPalindrome(stack);

     printf("\n================Question 2===============================\n");
     char exp[100];
     printf("Enter the expression:");
     scanf("%s", exp);
	infixToPostfix(exp);

     printf("\n================Question 3===============================\n");
     struct Stack* stack2 = create_Stack(100);
     is_Balanced(stack2);

	return 0;
}