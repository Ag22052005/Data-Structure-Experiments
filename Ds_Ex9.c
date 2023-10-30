#include <stdio.h>
#include <stdlib.h>
struct info
{
    int Marks, rollno;
};
struct node
{
    int id;
    struct info information;
    struct node *left, *right;
};
struct Binary_Search_tree
{
    struct node *root;
};
void insert(struct node *root, struct node *New_Node);
struct node *search(struct node *root, int search_data);
void Traverse(struct node *root);
struct node* Delete(struct node* root,int id);
struct node* smallest(struct node* root);
int List_Choice();
int main()
{
    struct Binary_Search_tree T1, T2;
    struct Binary_Search_tree *pointer_to_tree = NULL;
    struct node *temp, *ptn;
    T1.root = T2.root = NULL;
    int case_choice, search_data, insert_data, list_choice = 1,choice=2;
    do
    {
        if(choice == 2)
        {
        printf("\n**************************TREE MENU**************************\n");
        printf("1. TREE-1\n2. TREE-2");
        list_choice = List_Choice();
        if (list_choice == 1)
        {
            pointer_to_tree = &T1;
        }
        else
        {
            pointer_to_tree = &T2;
        }
        }
        printf("\n**************************MENU**************************\n");
        printf("1. Insert\n2. Delete\n3. Search\n4. Traverse\n5. Exit");
        printf("\nEnter your Choice: ");
        scanf("%d", &case_choice);
        switch (case_choice)
        {
        case 1:
            ptn = (struct node *)malloc(sizeof(struct node));
            ptn->left = ptn->right = NULL;
            printf("\nEnter the id:");
            scanf("%d",&(ptn->id));
            printf("\nEnter Roll No. And Marks respectively:");
            scanf("%d%d", &(ptn->information).rollno, &(ptn->information).Marks);
            if (pointer_to_tree->root == NULL)
            {
                pointer_to_tree->root = ptn;
            }
            else
            {
                insert(pointer_to_tree->root, ptn);
            }
            break;
        case 2:
            if(pointer_to_tree->root == NULL)
            {
                printf("\nTree Is Empty !!!  Can't Delete!!\n");
                break;
            }
            int tempid;
            printf("\nEnter the ID whose Information is to be Delete: ");
            scanf("%d",&tempid);
            pointer_to_tree->root = Delete(pointer_to_tree->root,tempid);
            break;
        case 3:
        if(pointer_to_tree->root==NULL)
        {
            printf("\nTree is Empty!!!!");
            break;
        }
            printf("\nEnter the id whose information is to be Search:");
            scanf("%d", &search_data);
            temp = search(pointer_to_tree->root, search_data);
            if (temp != NULL)
            {
                printf("\nSearched Id has following Information:");
                printf("\nRoll no. = %d\nMarks = %d", temp->information.rollno, temp->information.Marks);
                break;
            }
            printf("Id is Not present in Tree!");
            break;
        case 4:
            if(pointer_to_tree->root == NULL)
            {
                printf("\nTree is Empty!!!!");
            }
            printf("Elements are In Infix Order:\n");
            Traverse(pointer_to_tree->root);
            break;
        case 5:
            return 0;
        default:
            printf("\nInvalid Choice!!!! Try Again!!!");
            break;
        }
        printf("\n1. Continue in same Tree\n2. Go to Tree Menu");
        printf("\nEnter Choice: ");
        scanf("%d",&choice);
    } while (1);
    return 0;
}
void insert(struct node *root, struct node *New_Node)
{
    if (root->id >= New_Node->id)
    {
        if (root->left != NULL)
        {
            insert(root->left, New_Node);
        }
        else
        {
            root->left = New_Node;
            return;
        }
    }
    else
    {
        if (root->right != NULL)
        {
            insert(root->right, New_Node);
        }
        else
        {
            root->right = New_Node;
            return;
        }
    }
}
struct node* Delete(struct node* root,int id)
{
    if(id>root->id)
    root->right = Delete(root->right,id);
    else if(id<root->id)
    root->left = Delete(root->left,id);
    else
    {
        if(root->left == NULL)
        {
            struct node * temp = root->right;
            printf("Deleted Successfully");
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            struct node * temp = root->left;
            printf("Deleted Successfully");
            free(root);
            return temp;
        }
        else
        {
            struct node * temp = smallest(root->right);
            root->id = temp->id;
            root->right = Delete(root->right,temp->id);
        }
    }
    return root;
}
struct node *search(struct node *root, int search_data)
{
    if (root->id == search_data)
    {
        return root;
    }
    if (root->id > search_data)
    {
        if (root->left != NULL)
        {
            search(root->left, search_data);
        }
        else
        {
            return NULL;
        }
    }
    else
    {
        if (root->right != NULL)
        {
            search(root->right, search_data);
        }
        else
        {
            return NULL;
        }
    }
}
void Traverse(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    Traverse(root->left);
    printf("\nId = %d\n", root->id);
    printf("Roll No.: %d\nMarks : %d\n",root->information.rollno,root->information.Marks);
    Traverse(root->right);
}
int List_Choice()
{
    int list_choice = 3;
    while (list_choice != 1 && list_choice != 2)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &list_choice);
        if (list_choice < 1 || list_choice > 2)
        {
            printf("Wrong Input !! Please Try Again");
        }
    }
    return list_choice;
}
struct node* smallest(struct node* root)
{
    if(root->left == NULL)
    {
        return root;
    }
    else
    {
        return smallest(root->left);
    }
}