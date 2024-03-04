#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *lbranch, *rbranch;
};
typedef struct node *NODE;

NODE InsertNode(NODE root,int Item){
    NODE temp;
    temp= (NODE)malloc(sizeof(struct node));
    if(temp!=NULL){
    temp->info = Item;
    temp->lbranch = NULL;
    temp->rbranch = NULL;
    if (root == NULL)
		return temp;
	if (Item < root->info)
		root->lbranch = InsertNode(root->lbranch, Item);
	else if (Item > root->info)
		root->rbranch = InsertNode(root->rbranch, Item);
    }
	return root;
}
void PreOrder(NODE root){
    if (root != NULL){
        printf("%d\t", root->info);
        PreOrder(root->lbranch);
        PreOrder(root->rbranch);
    }
}
void InOrder(NODE root){
    if (root != NULL){
        InOrder(root->lbranch);
        printf("%d\t", root->info);
        InOrder(root->rbranch);
    }
}
void PostOrder(NODE root){
    if (root != NULL){
        PostOrder(root->lbranch);
        PostOrder(root->rbranch);
        printf("%d\t", root->info);
    }
}
void SearchBST(NODE root, int ele){
    if (root != NULL){
        if (ele < root->info)
            SearchBST(root->lbranch, ele);
        else if (ele > root->info)
            SearchBST(root->rbranch, ele);
        else
            printf("\n%d is found in the BST\n", ele);
    }
    else
        printf("\n%d is not found in the BST\n", ele);
}

int main(){
    NODE root = NULL;
    int Choice, Item, Num;
    printf("Create a BST of N Integers \n");
    printf("\nEnter the number N : ");
    scanf("%d", &Num);
    printf("\nEnter %d numbers\n", Num);
    for (int i = 0; i < Num; i++)
    {
        scanf("%d", &Item);
        root = InsertNode(root, Item);
    }
    printf("\n1.Inorder traversal\n2.Preorder traversal");
    printf("\n3.Postorder traversal\n4.Search\n5.Exit\n");
   while(1)
   {
        printf("\nEnter your choice : ");
        scanf("%d", &Choice);
        switch (Choice){
        case 1:
            if (root == NULL)
                printf("\nTree is Empty\n");
            else
            {
                printf("\nInorder Traversal is :\n");
                InOrder(root);
                printf("\n");
            }
            break;
        case 2:
            if (root == NULL)
                printf("\nTree is Empty\n");
            else
            {
                printf("\nPreorder Traversal is :\n");
                PreOrder(root);
                printf("\n");
            }
            break;
        case 3:
            if (root == NULL)
                printf("\nTree is Empty\n");
            else
            {
                printf("\nPostorder Traversal is :\n");
                PostOrder(root);
                printf("\n");
            }
            break;
        case 4:
            printf("\nEnter the element to be searched : ");
            scanf("%d", &Item);
            SearchBST(root, Item);
            break;
        case 5:
            exit(0);
        }
    }
}