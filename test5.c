
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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

void is_Balanced(struct Stack * stack)
{
     char exp[MAX];
     int i = 0;
     stack->top = -1;
     printf("\nINPUT THE EXPRESSION : ");
     scanf("%s", exp);
     for(i = 0;i < strlen(exp);i++)
     {
          if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
          {
               push_char(stack, exp[i]);
               continue;
          }
          else if(exp[i] == ')' || exp[i] == ']' || exp[i] == '}') // If a closed bracket is encountered
          {
               if(exp[i] == ')')
               {
                    if(stack->array[stack->top] == '(')
                    {
                         pop(stack); 
                    }
                    else
                    {
                         printf("\nUNBALANCED EXPRESSION\n");
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
                         printf("\nUNBALANCED EXPRESSION\n");
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
                         printf("\nUNBALANCED EXPRESSION\n");
                         break;
                    }
               }
          }
     }
     if(stack->top == -1)
     {
          printf("\nBALANCED EXPRESSION\n"); 
     }
}


int main(){
     struct Stack* stack = create_Stack(100);
     is_Balanced(stack);

     return 0;

}