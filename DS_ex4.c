#include <stdio.h>
#include <stdlib.h>
struct student
{
    int rollno;
    int marks;
};
struct queue
{
    int first, last;
    int max;
    struct student *array;
};
char isempty(struct queue *ptq);
char isfull(struct queue *ptq);
struct student *peek(struct queue *ptq, int i);
void enqueue(struct queue *ptq, struct student *pts);
struct student *dequeue(struct queue *ptq);
int main()
{
    struct queue q1, q2;
    struct queue *pointer_to_queue;
    struct student *temp;
    int choice, ch, x = 2, qch;
    q1.first = q2.first = 0;
    q1.last = q2.last = -1;
    q1.array = q2.array = NULL;
    printf("Enter the max value of First queue:");
    scanf("%d", &(q1.max));
    printf("Enter the max value of Seconnd queue:");
    scanf("%d", &(q2.max));
    q1.array = (struct student *)malloc((q1.max) * sizeof(struct student));
    q2.array = (struct student *)malloc((q2.max) * sizeof(struct student));
    do
    {
        if (x == 2)
        {
            do
            {
            printf("\n1. First Queue\n2. Second Queue");
            printf("\nEnter your choice\n");
            scanf("%d", &qch);
            if(qch !=1 && qch != 2)
            {
                printf("Invalid Choice !!! Try Again");
            }
            }while(qch !=1 && qch != 2);
        }
        if (qch == 1)
            pointer_to_queue = &q1;
        else if (qch == 2)
            pointer_to_queue = &q2;
        printf("\n1. Check for Empty\n2. Check for Full\n3. Enqueue\n4. Dequeue\n5. Peek\n6. Exit");
        printf("\nEnter Choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            if (isempty(pointer_to_queue))
                printf("\nQueue is Empty");
            else
                printf("\nQueue is not Empty");
            break;
        }
        case 2:
        {
            if (isfull(pointer_to_queue))
                printf("\nQueue is Full");
            else
                printf("\nQueue is not Full");
            break;
        }
        case 3:
        {
            if (isfull(pointer_to_queue))
                printf("\nCan not Enqueue");
            else
            {
                temp = (struct student *)malloc(sizeof(struct student));
                printf("\nEnter the details:");
                printf("\nRoll no. = ");
                scanf("%d", &((*temp).rollno));
                printf("Marks = ");
                scanf("%d", &((*temp).marks));
                enqueue(pointer_to_queue, temp);
            }
            break;
        }
        case 4:
        {
            if (isempty(pointer_to_queue))
                printf("\nCan not Dequeue");
            else
            {
                temp = dequeue(pointer_to_queue);
                printf("Dequeued Element:");
                printf("Roll No.= %d\nMarks = %d", ((*temp).rollno), ((*temp).marks));
            }
            break;
        }
        case 5:
        {
            if (isempty(pointer_to_queue))
                printf("\nQueue is Empty");
            else
            {
                printf("\n1. Front Peek\n2. End peek");
                printf("\nEnter choice:");
                scanf("%d", &ch);
                temp = peek(pointer_to_queue, ch);
                printf("peeked Element:");
                printf("\nRoll No.= %d\nMarks = %d", ((*temp).rollno), ((*temp).marks));
            }
            break;
        }
        case 6:
        {
            return 0;
        }
        default:
            printf("Invalid CHoice !!!! Please Try Again");
        }
        do
        {
            printf("\n1. Continue in same Queue\n2. Go to Queue Menu\n");
            scanf("%d", &x);
            if (x != 1 && x != 2)
                printf("\nInvalid Choice");
        } while (x != 1 && x != 2);
    } while (1);
}
char isempty(struct queue *ptq)
{
    if (((*ptq).last) < ((*ptq).first))
        return 1;
    else
        return 0;
}
char isfull(struct queue *ptq)
{
    if (((*ptq).last) == ((*ptq).max))
        return 1;
    else
        return 0;
}
struct student *peek(struct queue *ptq, int i)
{
    struct student *pts;
    if (i == 1)
    {
        pts = &((*ptq).array[(*ptq).first]);
        return pts;
    }
    else
    {
        pts = &((*ptq).array[(*ptq).last]);
        return pts;
    }
}
void enqueue(struct queue *ptq, struct student *new_student)
{
    (*ptq).last++;
    (*ptq).array[(*ptq).last] = *new_student;
}
struct student *dequeue(struct queue *ptq)
{
    struct student *pts;
    pts = &((*ptq).array[(*ptq).first]);
    (*ptq).first++;
    return pts;
}
