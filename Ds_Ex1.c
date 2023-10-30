#include <stdio.h>
#include <stdlib.h>
struct student
{
    int rollno;
    int marks;
};
typedef struct stack
{
    int max, top;
    struct student *pts;
} intstack;

char isEmpty(intstack *x);
char isFull(intstack *x);
void pop(intstack *x);
void push(intstack *x, struct student stu);
struct student peek(intstack *x);

int main()
{
    intstack s1;
    struct student stu;
    struct student temp;
    printf("Enter the Max Value of Stack:");
    scanf("%d", &(s1.max));
    s1.pts = (struct student *)malloc(((s1.max) + 1) * sizeof(struct student));
    s1.top = 0;
    int choice, ch;
    do
    {
        printf("\n********************** MENU **********************");
        printf("\n1. POP\n2. PUSH\n3. PEEK\n4. STACK IS EMPTY?\n5. STACK IS FULL?\n6. Exit");
        printf("\nEnter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            pop(&s1);
            break;
        }
        case 2:
        {
            printf("Enter the data that has to be push:");
            printf("\nRoll No. and Marks:");
            scanf("%d%d", &stu.rollno, &stu.marks);
            push(&s1, stu);
            break;
        }
        case 3:
        {
            if (isEmpty(&s1))
                printf("Stack Underflow");
            else
            {
                temp = peek(&s1);
                printf("Top Most Element:\n1. Roll No. = %d\n2. Marks = %d", temp.rollno, temp.marks);
            }
            break;
        }
        case 4:
        {
            if (isEmpty(&s1))
                printf("STACK UNDERFLOW");
            else
                printf("NOT EMPTY");
            break;
        }
        case 5:
        {
            if (isFull(&s1))
                printf("STACK OVERFLOW");
            else
                printf("NOT FULL");
            break;
        }
        case 6:
        {
            exit(1);
        }
        default:
        {
            printf("Invalid Choice");
        }
        }

    } while (1);

    return 0;
}
char isEmpty(intstack *x)
{
    if (x->top == 0)
        return 1;
    else
        return 0;
}
char isFull(intstack *x)
{
    if (x->top == x->max)
        return 1;
    else
        return 0;
}
void pop(intstack *x)
{
    if (isEmpty(x) == 0)
    {

        struct student temp = (*x).pts[x->top];
        x->top--;
        printf("Element who is poped:\n1. Roll No. = %d\n2. Marks = %d", temp.rollno, temp.marks);
    }
    else
        printf("\nStack Underflow");
}

void push(intstack *x, struct student stu)
{

    if (isFull(x) == 0)
    {
        (*x).top++;
        (*x).pts[x->top] = stu;
    }
    else
        printf("Stack Overflow");
}
struct student peek(intstack *x)
{
    struct student temp = (*x).pts[x->top];
    return temp;
}

// #include <stdio.h>
// #include <stdlib.h>
// typedef struct stack
// {
//     int max, top;
//     int *si;
// } intstack;

// int isEmpty(intstack *x);
// int isFull(intstack *x);
// void pop(intstack *x);
// void push(intstack *x, int i);
// int peek(intstack *x);

// int main()
// {
//     intstack s1;
//     printf("Enter the Max:");
//     scanf("%d", &(s1.max));
//     s1.si = (int *)malloc(((s1.max) + 1) * sizeof(int));
//     s1.top = 0;
//     int choice, ch;
//     do
//     {
//         printf("\n********************** MENU **********************");
//         printf("\n1. POP\n2. PUSH\n3. PEEK\n4. STACK IS EMPTY?\n5. STACK IS FULL?\n6. Exit");
//         printf("\nEnter your choice:");
//         scanf("%d", &choice);
//         switch (choice)
//         {
//         case 1:
//         {
//             pop(&s1);
//             break;
//         }
//         case 2:
//         {
//             int i;
//             printf("Enter the data that has to be push:");
//             scanf("%d", &i);
//             push(&s1, i);
//             break;
//         }
//         case 3:
//         {
//             printf("Top Most Element = %d", peek(&s1));
//             break;
//         }
//         case 4:
//         {
//             if (isEmpty(&s1))
//                 printf("STACK UNDERFLOW");
//             else
//                 printf("NOT EMPTY");
//             break;
//         }
//         case 5:
//         {
//             if (isFull(&s1))
//                 printf("STACK OVERFLOW");
//             else
//                 printf("NOT FULL");
//             break;
//         }
//         case 6:
//         {
//             exit(1);
//         }
//         default:
//         {
//             printf("Invalid Choice");
//         }
//         }

//     } while (1);

//     return 0;
// }
// int isEmpty(intstack *x)
// {
//     if (x->top == 0)
//         return 1;
//     else
//         return 0;
// }
// int isFull(intstack *x)
// {
//     if (x->top == x->max)
//         return 1;
//     else
//         return 0;
// }
// void pop(intstack *x)
// {
//     if (isEmpty(x) == 0)
//     {

//         int temp = x->si[x->top];
//         x->top--;
//         printf("Element whose is poped = %d", temp);
//     }
//     else
//         printf("\nStack Underflow");
// }

// void push(intstack *x, int i)
// {

//     if (isFull(x) == 0)
//     {
//         x->top++;
//         x->si[x->top] = i;
//     }
//     else
//         printf("Stack Overflow");
// }
// int peek(intstack *x)
// {
//     int temp = x->si[x->top];
//     return temp;
// }