// #include <stdio.h>
// #include <stdlib.h>
// struct Node
// {
//     int data;
//     struct Node *Next;
// };
// struct SLL
// {
//     struct Node *Head;
// };
// void add_front(struct Node **ph, struct Node *nn);
// void delete_front(struct Node **ph);
// void Traverse(struct Node *ph);
// void add_end(struct Node **ph, struct Node *nn);
// void delete_end(struct Node **ph);
// void add_position(struct Node **ph, struct Node *nn,int pos);
// void delete_position(struct Node **ph,struct Node *nn,int pos);
// int main()
// {
//     struct SLL s1;
//     struct Node *ptn;
//     struct Node *temp;
//     s1.Head= NULL;
//     int choice;
//     while(1)
//     {
//         printf("\n1. Add Front\n2. Delete Front\n3. Add End\n4. Delete End\n5. Add at Specified position\n6. Delete at Specified position\n7. Traverse\n8. Exit");
//         printf("\nEnter Your Choice:");
//         scanf("%d",&choice);
//         switch(choice)
//         {
//             case 1:
//             {
//                 ptn = (struct Node *)malloc(sizeof(struct Node));
//                 (*ptn).Next = NULL;
//                 printf("\nEnter the Data:");
//                 scanf("%d",&(*ptn).data);
//                 add_front(&s1.Head,ptn);
//                 break;
//             }
//             case 2:
//             {
//                 if(s1.Head==NULL)
//                 printf("\nLIST IS EMPTY.\nCan not Delete.\n");
//                 else
//                 delete_front(&s1.Head);
//                 break;
//             }
//             case 3:
//             {
//                 if(s1.Head==NULL)
//                 {
//                     printf("LIST IS EMPTY.Hence Addition is takes place at front.\n");
//                     ptn = (struct Node *)malloc(sizeof(struct Node));
//                     (*ptn).Next = NULL;
//                     printf("\nEnter the Data:");
//                     scanf("%d",&(*ptn).data);
//                     add_front(&s1.Head,ptn);
//                 }
//                 else
//                 {
//                     ptn = (struct Node *)malloc(sizeof(struct Node));
//                     (*ptn).Next = NULL;
//                     printf("\nEnter the Data:");
//                     scanf("%d",&(*ptn).data);
//                     add_end(&s1.Head,ptn);
//                 }
//                 break;
//             }
//
//             case 4:
//             {
//                 if(s1.Head==NULL)
//                 printf("\nLIST IS EMPTY.\nCan not Delete.\n");
//                 else
//                 delete_end(&s1.Head);
//                 break;
//             }
//             case 5:
//             {
//                 int pos;
//                 printf("\nEnter the Position Where the Node to be Inserted:");
//                 scanf("%d",&pos);
//                 ptn = (struct Node *)malloc(sizeof(struct Node));
//                 (*ptn).Next = NULL;
//                 if(pos==1)
//                 {
//                     printf("\nEnter the Data:");
//                     scanf("%d",&(*ptn).data);
//                     add_front(&s1.Head,ptn);
//                 }
//                 else{
//                     printf("\nEnter the Data:");
//                     scanf("%d",&(*ptn).data);
//                     add_position(&s1.Head,ptn,pos);
//                 }
//                 break;
//             }
//             case 6:
//             {
//                 int pos;
//                 printf("\nEnter the Position of node to be deleted:");
//                 scanf("%d",&pos);
//                 if(pos==1)
//                 {
//                     if(s1.Head==NULL)
//                     printf("\nLIST IS EMPTY.\nCan not Delete.\n");
//                     else
//                     delete_front(&s1.Head);
//                 break;
//                 }
//                 else
//                 {
//                     delete_position(&s1.Head,ptn,pos);
//                 }
//                 break;
//             }
//             case 7:
//             {
//                 if(s1.Head==NULL)
//                 printf("\nLIST IS EMPTY");
//                 else
//                 Traverse(s1.Head);
//                 break;
//             }
//             case 8:
//             {
//                 exit(1);
//                 break;
//             }
//             default:
//             {
//                 printf("\nInvalid Choice.");
//                 break;
//             }

//         }

//     }
// }
// void add_front(struct Node **ph, struct Node *nn)
// {
//     (*nn).Next = *ph;
//     *ph = nn;
// }
// void delete_front(struct Node **ph)
// {
//     struct Node *temp = *ph;
//     *ph = (*(*ph)).Next;
//     free(temp);
// }
// void Traverse(struct Node *ph)
// {
//     struct Node *temp = ph;
//     while ((*temp).Next != NULL)
//     {
//         printf("%d\t", (*temp).data);
//         temp = (*temp).Next;
//     }
//     printf("%d\t", (*temp).data);
// }
// void add_end(struct Node **ph, struct Node *nn)
// {
//     struct Node * temp;
//     temp = *ph;
//     while ((*temp).Next != NULL)
//     {
//         temp = (*temp).Next;
//     }
//     (*temp).Next = nn;
// }
// void delete_end(struct Node **ph)
// {
//     struct Node *previous_node;
//     struct Node *last_node;
//     last_node = *ph;
//     while((*last_node).Next!=NULL)
//     {
//         previous_node = last_node ;
//         last_node = (*last_node).Next;
//     }
//     (*previous_node).Next = NULL;
//     free(last_node);
// }
// void add_position(struct Node **ph,struct Node *nn,int pos)
// {
//     struct Node *last_node;
//     struct Node *pre_node;
//     struct Node *temp = *ph;
//     last_node = *ph;
//     int x=1;
//     while((*temp).Next!=NULL)
//     {
//         temp = (*temp).Next;
//         x++;
//     }
//     if(x>=pos)
//     {
//     while(pos>1)
//     {
//         pre_node= last_node;
//         last_node = (*last_node).Next;
//         pos--;
//     }
//         (*pre_node).Next = nn;
//         (*nn).Next = last_node;
//     }
//     // else if((*temp).Next==NULL)
//     // {
//     //     add_end(ph,nn);
//     // }
//     else
//     printf("\nposition greater than linkedlist length");
// }
// void delete_position(struct Node **ph,struct Node *nn,int pos)
// {
//     if(*ph!=NULL)
//     {
//     struct Node *pre_node;
//     struct Node *last_node;
//     struct Node *temp = *ph;
//     last_node = *ph;
//     int x=1;
//     while((*temp).Next!=NULL)
//     {
//         temp = (*temp).Next;
//         x++;
//     }
//     if(pos<=x)
//     {
//     while(x<pos)
//     {
//         pre_node = last_node ;
//         last_node = (*last_node).Next;
//         x++;
//     }
//     (*pre_node).Next = (*last_node).Next;
//     free(last_node);
//     }
//     else
//     printf("\nposition greater than linkedlist length");
//     }
//     else
//     printf("\n List Is Empty.");
// }

//                                                  FOR 2 LIST

#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *Next;
};
struct SLL
{
    struct Node *Head;
};
void add_front(struct Node **ph, struct Node *nn);
struct Node *delete_front(struct Node **ph);
void Traverse(struct Node *ph);
void add_end(struct Node **ph, struct Node *nn);
struct Node *delete_end(struct Node **ph);
void add_position(struct Node **ph, struct Node *nn, int pos);
struct Node *delete_position(struct Node **ph, struct Node *nn, int pos);
int size(struct Node **ph);
int main()
{
    struct SLL s1, s2;
    struct Node *ptn;
    struct Node *temp;
    s1.Head = NULL;
    s2.Head = NULL;
    int choice;
    int li_ch, menu_ch, x = 2;
    struct SLL *pointer_to_list;
    do
    {
        if (x == 2)
        {
            printf("\n1. List-1\n2. List-2");
            printf("\nEnter the List Number:");
            scanf("%d", &li_ch);
            if (li_ch == 1)
                pointer_to_list = &s1;
            else if (li_ch == 2)
                pointer_to_list = &s2;
            else
            {
                printf("\nInvalid Choice");
                return 0;
            }
        }
        printf("\n********************** MENU **********************");
        printf("\n1. Add Front\n2. Delete Front\n3. Add End\n4. Delete End\n5. Add a Node at Specified position\n6. Delete a Node of Specified position\n7. Traverse\n8. Exit");
        printf("\nEnter Your Choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            ptn = (struct Node *)malloc(sizeof(struct Node));
            (*ptn).Next = NULL;
            printf("\nEnter the Data:");
            scanf("%d", &(*ptn).data);
            add_front(&((*pointer_to_list).Head), ptn);
            break;
        }
        case 3:
        {
            ptn = (struct Node *)malloc(sizeof(struct Node));
            (*ptn).Next = NULL;
            printf("\nEnter the Data:");
            scanf("%d", &(*ptn).data);
            if (((*pointer_to_list).Head) == NULL)
                add_front(&((*pointer_to_list).Head), ptn);
            else
            {
                add_end(&((*pointer_to_list).Head), ptn);
            }
            break;
        }
        case 2:
        {
            if (((*pointer_to_list).Head) == NULL)
                printf("\nLIST IS EMPTY\nCAN'T DELETE\n");
            else
            {
                temp = delete_front(&((*pointer_to_list).Head));
                printf("Deleted Element : %d", temp->data);
            }
            break;
        }
        case 4:
        {
            if (((*pointer_to_list).Head) == NULL)
                printf("\nLIST IS EMPTY\nCAN'T DELETE\n");
            else if ((*(*pointer_to_list).Head).Next == NULL)
            {
                free((*pointer_to_list).Head);
                (*pointer_to_list).Head = NULL;
            }
            else
                temp = delete_end(&((*pointer_to_list).Head));

            printf("Deleted Element : %d", temp->data);
            break;
        }
        case 5:
        {
            int pos;
            ptn = (struct Node *)malloc(sizeof(struct Node));
            (*ptn).Next = NULL;
            printf("\nEnter the Data:");
            scanf("%d", &(*ptn).data);
            printf("\nEnter the Position Where the Node to be Inserted:");
            scanf("%d", &pos);
            if (pos == 1)
            {
                add_front(&((*pointer_to_list).Head), ptn);
            }
            else if ((*pointer_to_list).Head == NULL)
            {
                printf("\nList IS Empty !!!! So Can't Add at this position");
            }
            else
            {
                add_position(&((*pointer_to_list).Head), ptn, pos);
            }
            break;
        }
        case 6:
        {
            if ((*pointer_to_list).Head == NULL)
            {
                printf("List is Empty\n Can't delete");
                break;
            }
            int pos;
            printf("\nEnter the Position of node to be deleted:");
            scanf("%d", &pos);
            if (pos == 1)
            {
                temp = delete_front(&((*pointer_to_list).Head));
            }
            else
            {
                temp = delete_position(&((*pointer_to_list).Head), ptn, pos);
            }
                if(temp!=NULL)
                printf("Deleted Element : %d", temp->data);
            break;
        }
        case 7:
        {
            if (((*pointer_to_list).Head) == NULL)
                printf("\nLIST IS EMPTY");
            else
                Traverse(((*pointer_to_list).Head));
            break;
        }
        case 8:
        {
            return 0;
        }
        default:
        {
            printf("\nInvalid Choice.");
            break;
        }
        }
        printf("\n1. Do you want to continue in same list\n2. Go to List Menu");
        printf("\nEnter Choice:");
        scanf("%d", &menu_ch);
        x = menu_ch;
    } while (1);
}
void add_front(struct Node **ph, struct Node *nn)
{
    (*nn).Next = *ph;
    *ph = nn;
}
struct Node *delete_front(struct Node **ph)
{
    struct Node *temp = *ph;
    *ph = (*(*ph)).Next;
    return temp;
}
void Traverse(struct Node *ph)
{
    struct Node *temp = ph;
    printf("\nElements are:\n");
    while ((*temp).Next != NULL)
    {
        printf("%d\t", (*temp).data);
        temp = (*temp).Next;
    }
    printf("%d\t", (*temp).data);
}
void add_end(struct Node **ph, struct Node *nn)
{
    struct Node *temp;
    temp = *ph;
    while ((*temp).Next != NULL)
    {
        temp = (*temp).Next;
    }
    (*temp).Next = nn;
}
struct Node *delete_end(struct Node **ph)
{
    struct Node *previous_node;
    struct Node *last_node;
    previous_node =last_node = *ph;
    while (previous_node->Next->Next != NULL)
    {
        previous_node = (*previous_node).Next;
    }
    (last_node) = (*previous_node).Next;
    (*previous_node).Next = NULL;
    return last_node;
}
void add_position(struct Node **ph, struct Node *nn, int pos)
{
    struct Node *last_node;
    last_node = *ph;
    pos--;
    while (pos > 1 && last_node->Next != NULL)
    {
        last_node = last_node->Next;
        pos--;
    }
    if (pos > 1)
    {
        printf("\nPosition is Greater than linked list Length");
    }
    else
    {
        nn->Next = last_node->Next;
        last_node->Next = nn;
    }
}
struct Node *delete_position(struct Node **ph, struct Node *nn, int pos)
{
    struct Node *pre_node;
    struct Node *last_node;
    last_node=pre_node = *ph;
    while (pos > 1 && last_node->Next!=NULL)
    {
        pre_node = last_node;
        last_node= last_node->Next;
        pos--;
    }
    if (pos > 1)
    {
        printf("\nPosition is Greater than linked list Length");
        return NULL;
    }
    else
    {
    last_node = pre_node->Next;
    pre_node->Next = last_node->Next;
    return last_node;
    }
}
int size(struct Node **ph)
{
    int x = 0;
    struct Node *temp = *ph;
    if (*ph == NULL)
        return x;
    while (temp->Next != NULL)
    {
        temp = temp->Next;
        x++;
    }
    return x;
}