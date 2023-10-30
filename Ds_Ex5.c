#include <stdio.h>
#include <stdlib.h>
struct Passenger_info
{
	unsigned int id;
};
struct cq
{
	unsigned int max, front, rear;
	struct Passenger_info *arr;
};
char isEmpty(struct cq *pq);
char isFull(struct cq *pq);
void enqueue(struct cq *pq, struct Passenger_info *information);
void Display(struct cq *pq);
int show(struct cq *pq,int choice);
struct Passenger_info *dequeue(struct cq *pq);
int main()
{
	typedef struct Passenger_info pi;
	struct cq queue;
	struct cq *pointer_to_queue;
	queue.front = 0;
	queue.rear = 0;
	printf("Enter the max value of queue:");
	scanf("%d", &(queue.max));
	queue.arr = (pi *)malloc((++queue.max) * sizeof(pi));
	int choice, data;
	struct Passenger_info *information;
	pointer_to_queue = &queue;
	do
	{
		printf("\n********************** MENU **********************");
		printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Peek\n5. Queue IS EMPTY?\n6. Queue IS FULL?\n7. Exit");
		printf("\nEnter your choice:");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			if (isFull(pointer_to_queue) == 1)
			{
				printf("Queue is Full");
			}
			else
			{
				information = (pi *)malloc(sizeof(pi));
				printf("Enter the data:");
				scanf("%d", &(information->id));
				enqueue(pointer_to_queue, (information));
			}
			break;
		case 2:
			if (isEmpty(pointer_to_queue) == 1)
			{
				printf("Queue is Empty");
			}
			else
			{
				information = dequeue(pointer_to_queue);
				printf("Dequeue Element = %d", information->id);
			}
			break;
		case 3:
			if (isEmpty(pointer_to_queue) == 1)
			{
				printf("Queue is Empty");
			}
			else
			{
				Display(pointer_to_queue);
			}
			break;
		case 4: 
			if (isEmpty(pointer_to_queue) == 1)
			{
				printf("Queue is Empty");
			}
			else
			{
				int peekchoice,peekvalue;
				do{
				printf("\n1. Front\n2. Rear");
				printf("\nEnter Your Choice: ");
				scanf("%d",&peekchoice);
				if(peekchoice!=1 && peekchoice!=2)
				{
					printf("\nIncorrect Choice !!!  Try Again");
				}
				}while(peekchoice!=1 && peekchoice!=2);
				if(peekchoice==1)
				{
					printf("Front ID in Queue: %d",show(pointer_to_queue,peekchoice));
				}
				else
				{
					printf("Rear ID in Queue: %d",show(pointer_to_queue,peekchoice));
				}
			}
			break;
		case 5:
			if (isEmpty(pointer_to_queue) == 1)
				printf("Queue is Empty");
			else
				printf("Queue is not empty");
			break;
		case 6:
			if (isFull(pointer_to_queue) == 1)
				printf("Queue is Full");
			else
				printf("Queue is not Full");
			break;
		case 7:
			return 0;
			break;
		default:
			printf("Invalid Choice:");
		}
	} while (1);
}
char isEmpty(struct cq *pq)
{
	if (pq->front == pq->rear)
		return 1;
	return 0;
}
char isFull(struct cq *pq)
{
	if (((pq->rear) + 1) % pq->max == pq->front)
		return 1;
	return 0;
}
void enqueue(struct cq *pq, struct Passenger_info *information)
{
	pq->rear = (pq->rear + 1) % (pq->max);
	pq->arr[pq->rear] = *information;
}
struct Passenger_info *dequeue(struct cq *pq)
{
	struct Passenger_info *information;
	pq->front = (pq->front + 1) % pq->max;
	information = &(pq->arr[pq->front]);
	return (information);
}
void Display(struct cq *pq)
{
	printf("ID's in Queue: \n");
	int i = pq->front;
	if (pq->front < pq->rear)
	{
		while (i < pq->rear)
		{
			printf("%d\t", pq->arr[i + 1]);
			i++;
		}
	}
	else
	{
		while (i < (pq->max-1))
		{
			printf("%d\t", pq->arr[i + 1]);
			i++;
		}
		i = 0;
		while (i <= pq->rear)
		{
			printf("%d\t", pq->arr[i]);
			i++;
		}
	}
}
int show(struct cq *pq,int choice)
{
	struct Passenger_info *temp;
	if(choice==1)
	{
		temp = &(pq->arr[((pq->front)+1)%pq->max]);
		return temp->id;
	}
		temp = &(pq->arr[pq->rear]);
		return temp->id;
}