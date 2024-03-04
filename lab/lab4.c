#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#define MAX_SIZE 20
int top = -1;
float stack[MAX_SIZE];
void push(float s)
{
    stack[++top] = s;
}
float pop()
{
    return stack[top--];
}
float eval_postfix(char postfix[])
{
    float op1, op2;
    char s;
    for (int i = 0; i < strlen(postfix); i++)
    {
        s = postfix[i];
        if (isalpha(s))
        {
            float value;
            printf("Enter the value of %c: ", s);
            scanf("%f", &value);
            push(value);
        }
        else
        {
            op2 = pop();
            op1 = pop();
            switch (s)
            {
                case '+':
                    push(op1 + op2);
                    break;
                case '-':
                    push(op1 - op2);
                    break;
                case '*':
                    push(op1 * op2);
                    break;
                case '/':
                    push(op1 / op2);
                    break;
                case '%':
                    push((int)op1 % (int)op2);
                    break;
                case '^':
                    push(pow(op1, op2));
                    break;
                default:
                printf("invalid operator");
            }
        }
    }
    return pop();
}
int main()
{
    char postfix[MAX_SIZE];
    printf("Enter the valid postfix expression:\n");
    gets(postfix);
    printf("Result is %.2f\n", eval_postfix(postfix));
}
