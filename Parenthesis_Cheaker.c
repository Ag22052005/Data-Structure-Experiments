#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct stack
{
    int top;
    char *array;
};

void push(struct stack *x, char ch);
void pop(struct stack *x);

int main()
{
    struct stack s;
    s.top = -1;
    s.array = NULL;
    char str[20];
    int len, i = 0;

    printf("Enter a String:");
    scanf("%s", str);

    len = strlen(str);
    s.array = (char *)malloc((len + 1) * sizeof(char));

    while (str[i] != '\0')
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
            push(&s, str[i]);
        else if (str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
            if ((str[i] == ')' && s.top != -1 && s.array[s.top] == '(') ||
                (str[i] == '}' && s.top != -1 && s.array[s.top] == '{') ||
                (str[i] == ']' && s.top != -1 && s.array[s.top] == '['))
            {
                pop(&s);
            }
            else
            {
                push(&s, str[i]);
            }
        }
        i++;
    }

    if (s.top == -1)
        printf("Brackets are Perfect\n");
    else
        printf("Brackets are Not perfect\n");

    free(s.array); 
    return 0;
}

void push(struct stack *x, char ch)
{
    (*x).top++;
    (*x).array[(*x).top] = ch;
}

void pop(struct stack *x)
{
    (*x).top--;
}
