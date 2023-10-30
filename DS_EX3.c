#include<stdio.h>
#include<string.h>
struct stack
{
    unsigned int top;
    int *array;
};
int main()
{
    struct stack s;
    s.top = (int)-1;
    s.array = NULL;
    int length;
    printf("Entre the length of Expression:");
    scanf("%d",&length);
    s.array = (int *)malloc((length/2)*sizeof(int));
    char post_expression[length];
    printf("Enter the Postfix Expression:");
}