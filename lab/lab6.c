#include <stdio.h>
#include <stdlib.h>
struct node
{
    char usn[10], name[10];
    float avg_mar;
    struct node *link;
};
typedef struct node *Node;
Node GetNode()
{
    Node new;
    new = (Node)malloc(sizeof(struct node));
    printf("\nEnter USN : ");
    scanf("%s", new->usn);
    printf("\nEnter name : ");
    scanf("%s", new->name);
    printf("\nEnter Average Marks : ");
    scanf("%f", &new->avg_mar);
    new->link = NULL;
    return new;
}
void InsRear(Node *start)
{
    Node temp, ptr;
    temp = GetNode();
    if (*start == NULL)
    {
        *start = temp;
        return;
    }
    ptr = *start;
    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = temp;
}
void DelFront(Node *start)
{
    Node temp;
    if (*start == NULL)
    {
        printf("\nSLL is empty cannot deleted");
        return;
    }
    temp = *start;
    *start = (*start)->link;
    printf("\nNode deleted is %sn", temp->name);
    free(temp);
}
void InsFront(Node *start)
{
    Node temp;
    temp = GetNode();
    if (temp!=NULL)
    {
        temp->link = *start;
        *start = temp;
    }
    
}
void DelRear(Node *start)
{
    Node temp;
    if (*start == NULL)
    {
        printf("\nSLL is empty cannot delete\n");
        return;
    }
    temp = *start;
    if ((*start)->link == NULL)
    {
        *start = NULL;
        printf("\nNode deleted for %s\n", temp->name);
        free(temp);
        return;
    }
    while (temp->link->link != NULL)
    {
        temp = temp->link;
    }
    printf("\nNode deleted for %s\n", temp->name);
    free(temp->link);
    temp->link = NULL;
}
void Display(Node start)
{
    Node ptr;
    int count = 0;
    if (start == NULL)
    {
        printf("\nSLL is empty\n");
        return;
    }
    printf("\nThe contents of SLL are :\n");
    ptr = start;
    printf("\nUSN\tName\tAverage marks");
    while (ptr != NULL)
    {
        printf("\n%s %10s %10.2f", ptr->usn, ptr->name, ptr->avg_mar);
        ptr = ptr->link;
        count++;
    }
    printf("\nSLL has %d nodes\n", count);
}
void main()
{
    Node start = NULL;
    int Choice, Num, i;
    printf("\nEnter the number of Students N : ");
    scanf("%d", &Num);
    for (i = 0; i < Num; i++)
    {
        printf("\nEnter Data for Node %d :\n", i + 1);
        InsFront(&start);
    }
    printf("\nQUEUE OPERATIONS\n");
    printf("====================");
    printf("\n1.Insert Front\n2.Insert Rear\n3.Delete Front\n4.Delete Rear\n5.Display\n6.Exit\n");
    printf("====================");
    while (1)
    {
        printf("\nEnter your choice\n");
        scanf("%d", &Choice);
        switch (Choice)
        {
        case 1:
            InsFront(&start);
            break;
        case 2:
            InsRear(&start);
            break;
        case 3:
            DelFront(&start);
            break;
        case 4:
            DelRear(&start);
            break;
        case 5:
            Display(start);
            break;
        case 6:
            exit(0);
        }
    }
}
