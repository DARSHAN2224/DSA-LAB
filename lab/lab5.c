#include <stdio.h>
#include <stdlib.h>*9
#define size 7
char cq[size];
int r = -1, f = 0, cnt = 0;
void cq_insert()
{
    if (cnt == size)
    {
        printf("cq is full\n");
        return;
    }
    printf("enter the rainbow color\n");
    r = (r + 1) % size;
    scanf(" %c", &cq[r]);
    cnt++;
}
void del()
{
    if (cnt == 0)
    {
        printf("cq is empty\n");
        return;
    }
    printf("the deleted rainbow color is %c", cq[f]);
    f = (f + 1) % size;
    cnt--;
}
void display()
{
    int i, k = f;
    if (cnt == 0)
    {
        printf("cq is empty\n");
        return;
    }
    printf("\ncq rainbow color are \n");
    for (i = 0; i < cnt; i++)
    {
        printf("%c ", cq[k]);
        k = (k + 1) % size;
    }
}
int main()
{
    int ch;
    printf("------------Menu Details----------");
    printf("\n1.cq_insert\n2.cq_delete\n3.cq_display\n4.exit\n");
    printf("----------------------------------\n");
    while (1)
    {
        printf("enter your choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                cq_insert();
                break;
            case 2:
                del();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("wrong choice");
        }
    }
}