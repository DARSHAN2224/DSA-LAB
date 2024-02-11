#include <stdio.h>
#include <stdlib.h>
#define max 3
int a[10], top = -1;
void push()
{
    if (top == max - 1)
        printf("stack overflow\n");
    else
    {
        printf("enter an element\n");
        scanf("%d", &a[++top]);  
    }
}
int pop()
{
    if (top == -1)
        printf("stack underflow\n");
    else
    {
        printf("the poped element is %d\n", a[top--]);
        return;
    }
}
void display()
{
    if (top == -1)
        printf("stack is empty\n");
    else
    {
        printf("the elements are\n");
        for (int i = top; i >= 0; i--)
            printf("%d\t", a[i]);
    }
}
void palin()
{
    int i = 0, j = top;
    while (i <= j)
    {
        if (a[i] != a[j])
        {
            printf("It is not a palindrome\n");
            return;
        }
        i++;
        j--;
    }

    printf("it is a palindrome\n");
}
int main()
{
    int c;
    printf("------------Menu Details----------");
    printf("\n1.push\n2.pop\n3.display\n4.palindrome\n");
    printf("----------------------------------\n");
    while (1)
    {

        printf("\nEnter your choice\n");

        scanf("%d", &c);
        switch (c)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                palin();
                break;
            case 5:
                exit(0);
        }
    }
}