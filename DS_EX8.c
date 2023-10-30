// #include <stdio.h>
// #include <stdlib.h>
// struct Node
// {
//     int data;
//     struct Node *Next;
// };
// struct Stack
// {
//     struct Node *top;
// };
// void push(struct Node **ph, struct Node *nn);
// struct Node *pop(struct Node **ph);
// struct Node *peek(struct Node **ph);
// int main()
// {
//     struct Stack s1, s2;
//     struct Node *ptn;
//     struct Node *temp;
//     int choice;
//     int li_ch, menu_ch, x = 2;
//     struct Stack *pointer_to_stack;
//     s1.top = NULL;
//     s2.top = NULL;

//     do
//     {
// 	if (x == 2)
// 	{
// 	    printf("\n1. Stack-1\n2. Stack-2");
// 	    printf("\nEnter the Stack Number:");
// 	    scanf("%d", &li_ch);
// 	    if (li_ch == 1)
// 		pointer_to_stack = &s1;
// 	    else if (li_ch == 2)
// 		pointer_to_stack = &s2;
// 	    else
// 		{
// 		printf("\nInvalid Choice");
// 		exit(1);
// 		}
// 	}
// 	else if (x > 2)
// 	    printf("Invalid Choice");
// 	printf("\n1. push\n2. pop\n3. PEEK\n4. Exit");
// 	printf("\nEnter Your Choice:");
// 	scanf("%d", &choice);
// 	switch (choice)
// 	{
// 	case 1:
// 	{
// 	    ptn = (struct Node *)malloc(sizeof(struct Node));
// 	    (*ptn).Next = NULL;
// 	    printf("\nEnter the Data:");
// 	    scanf("%d", &(*ptn).data);
// 	    push(&((*pointer_to_stack).top), ptn);
// 	    break;
// 	}
// 	case 2:
// 	{
// 	    if (((*pointer_to_stack).top) == NULL)
// 		printf("\nLIST IS EMPTY\nCAN'T DELETE\n");
// 	    else
// 	    {
// 	       temp = pop(&((*pointer_to_stack).top));
// 		printf("Poped Element = %d",(*temp).data);
// 	    }
// 	    break;
// 	}
// 	case 3:
// 	{
// 	    if (((*pointer_to_stack).top) == NULL)
// 		printf("\nLIST IS EMPTY");
// 	    else
// 	    {
// 		temp = peek(&((*pointer_to_stack).top));
// 		printf("Top Most Element = %d",(*temp).data);
// 	    }
//         break;
// 	}
// 	case 4:
// 	{
// 	    exit(1);
// 	    break;
// 	}
// 	default:
// 	{
// 	    printf("\nInvalid Choice.");
// 	    break;
// 	}
// 	}
// 	printf("\n1. Do you want to continue in same list\n2. Go to List Menu");
// 	printf("\nEnter Choice:");
// 	scanf("%d", &menu_ch);
// 	x = menu_ch;

//     } while (1);
// }
// void push(struct Node **ph, struct Node *nn)
// {
//     (*nn).Next = *ph;
//     *ph = nn;
// }
// struct Node *pop(struct Node **ph)
// {
//     struct Node *temp = *ph;
//     *ph = (*(*ph)).Next;
//     return (temp);
// }
// struct Node *peek(struct Node **ph)
// {
// struct Node *temp=*ph;
// return (temp);
// }

#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int data;
	struct Node *Next;
};
struct Stack
{
	struct Node *top;
};
void push(struct Stack *ph, struct Node *nn);
struct Node *pop(struct Stack *ph);
struct Node *peek(struct Stack *ph);
char isempty(struct Stack *ph);
int main()
{
	struct Stack s1, s2;
	struct Node *ptn;
	struct Node *temp;
	int choice;
	int li_ch, menu_ch = 2;
	struct Stack *pointer_to_stack;
	s1.top = NULL;
	s2.top = NULL;

	do
	{
		if (menu_ch == 2)
		{
			do
			{
			printf("\n1. Stack-1\n2. Stack-2");
			printf("\nEnter the Stack Number:");
			scanf("%d", &li_ch);
			if (li_ch == 1)
				pointer_to_stack = &s1;
			else if (li_ch == 2)
				pointer_to_stack = &s2;
			else
			{
				printf("\nInvalid Choice");
			}
			}while(li_ch !=1 && li_ch !=2);
		}
		printf("\n********************** MENU **********************");
		printf("\n1. PUSH\n2. POP\n3. PEEK\n4. IsEmpty?\n5. Exit");
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
			push((pointer_to_stack), ptn);
			break;
		}
		case 2:
		{
			if (isempty(pointer_to_stack))
				printf("\nStack Underflow");
			else
			{
				temp = pop((pointer_to_stack));
				printf("Poped Element = %d\n", (*temp).data);
			}
			break;
		}
		case 3:
		{
			if (isempty(pointer_to_stack))
				printf("\nStack Underflow");
			else
			{
				temp = peek((pointer_to_stack));
				printf("Top Most Element = %d", (*temp).data);
			}
			break;
		}
		case 4:
			if (isempty(pointer_to_stack))
				printf("\nStack Underflow");
			else
				printf("\nStack is Not Empty");
				break;

		case 5:
		{
			exit(1);
			break;
		}
		default:
		{
			printf("\nInvalid Choice.");
			break;
		}
		}
		do
		{
		printf("\n1. Do you want to continue in same Stack\n2. Go to Stack Menu");
		printf("\nEnter Choice:");
		scanf("%d", &menu_ch);
		if(menu_ch !=1 && menu_ch != 2)
		printf("\nInvalid Choice !!! Please Try Again");
		}while(menu_ch !=1 && menu_ch != 2);

	} while (1);
}
void push(struct Stack *ph, struct Node *nn)
{
	(*nn).Next = ph->top;
	ph->top = nn;
}
struct Node *pop(struct Stack *ph)
{
	struct Node *temp = ph->top;
	ph->top = (ph->top)->Next;
	return (temp);
}
struct Node *peek(struct Stack *ph)
{
	struct Node *temp = ph->top;
	return (temp);
}
char isempty(struct Stack *ph)
{
	if (ph->top == NULL)
		return 1;
	else
		return 0;
}