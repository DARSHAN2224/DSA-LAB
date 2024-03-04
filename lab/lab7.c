#include <stdio.h>
#include <stdlib.h>
struct node
{
    int ssn, sal;
    char name[30], dept[4], desig[30], phno[11];
    struct node *lptr, *rptr;
};
typedef struct node *Node;
Node start = NULL;
Node get_node()
{
    Node new;
    new = (Node)malloc(sizeof(struct node));
    if (new != NULL)
    {
        printf("\nEnter SSN : ");
        scanf("%d", &new->ssn);
        printf("\nEnter name : ");
        scanf("%s", new->name);
        printf("\nEnter Department : ");
        scanf("%s", new->dept);
        printf("\nEnter Designation : ");
        scanf("%s", new->desig);
        printf("\nEnter Salary : ");
        scanf("%d", &new->sal);
        printf("\nEnter Phone no : ");
        scanf("%s", new->phno);
        new->lptr = NULL;
        new->rptr = NULL;
        return new;
    }
}

void insert_start()
{
    Node temp;
    temp = get_node();
    if (temp != NULL)
    {
        temp->rptr = start;
        start = temp;
    }
}
void insert_end()
{
    Node temp, ptr;
    ptr = start;
    temp = get_node();
    if (start == NULL)
    {
        start = temp;
        return;
    }
    while (ptr->rptr != NULL)
    {
        ptr = ptr->rptr;
    }
    ptr->rptr = temp;
    temp->lptr = ptr;
}
void delete_start()
{
    Node ptr = start;
    if (start == NULL)
    {
        printf("list is empty\n");
        return;
    }
    start = start->rptr;
    free(ptr);
}
void delete_end()
{
    Node ptr = start;
    if (start == NULL)
    {
        printf("list is empty\n");
        return;
    }
    while (ptr->rptr->rptr != NULL)
    {
        ptr = ptr->rptr;
    }
    free(ptr->rptr);
    ptr->rptr = NULL;
}
void display()
{
    int count = 0;
    if (start == NULL)
    {
        printf("\nDLL is empty\n");
        return;
    }
    printf("\nThe contents of DLL are :\n");
    printf("\nSSN\tName\tDept\tDesignation\tSalary\tPhone No");
    Node ptr = start;
    while (ptr != NULL)
    {
        printf("\n%5d\t%s\t%s\t%s\t%7d\t%11s", ptr->ssn, ptr->name, ptr->dept, ptr->desig, ptr->sal, ptr->phno);
        ptr = ptr->rptr;
        count++;
    }
    printf("\nDLL has %d nodes\n", count);
}

void main()
{
    int num;
    printf("nEnter the number of Employees N : ");
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        printf("nEnter Data for Node %d :n", i + 1);
        insert_end(start);
    }
    printf("\nQUEUE OPERATIONSn");
    printf("====================");
    printf("\nenter\n1.insert start\n2.insert end\n3.delete start\n4.delete end\n5.display\n6.exit\n");
    printf("====================");
    while (1)
    {
        printf("Enter your choice\n");
        int ch;
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert_start();
            break;
        case 2:
            insert_end();
            break;
        case 3:
            delete_start();
            break;
        case 4:
            delete_end();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
        }
    }
}