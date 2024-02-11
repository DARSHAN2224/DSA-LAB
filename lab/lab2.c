#include <stdio.h>
#include <stdlib.h> 
void array(int *n, int *p)
{
	printf("enter the array size:");
	scanf("%d",n);
	printf("enter the array elements\n");
	for (int i = 0; i < *n; i++)
		scanf("%d",(p+i));
}
void insert(int *n, int *p)
{
    int pos, ele, i;
    printf("Enter the position: ");
    scanf("%d", &pos);
    printf("Element to be inserted: ");
    scanf("%d", &ele);
    for (i = *n - 1; i >= pos-1; i--)
        p[i + 1] = p[i];
    p[i + 1] = ele;
    (*n)++;
}
void delete (int *n, int *p)
{
    int pos, i;
    printf("Enter the position to be deleted: ");
    scanf("%d", &pos);
    printf("Deleted element is %d\n", p[pos - 1]);
    for (i = pos - 1; i < *n - 1; i++)
        p[i] = p[i + 1];
    (*n)--;
}
void display(int *n, int *p)
{
    for (int i = 0; i < *n; i++)
        printf("%d ", *(p + i));
    printf("\n");
}
int main()
{
    int ch;
    int n,p[10];
	array(&n,p);
	while (1)
    {
        printf("Enter the choice. 1.Insert 2.Delete 3.Display 4.Exit: ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                insert(&n, p);
                break;
            case 2:
                delete (&n, p);
                break;
            case 3:
                display(&n, p);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}