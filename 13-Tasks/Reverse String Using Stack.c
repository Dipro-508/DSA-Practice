#include <stdio.h>
#define MAX 100
int main()
{
    char str[MAX];
    char stack[MAX];
    int top = -1;
    printf("Enter a string: ");
    fgets(str, MAX, stdin);

    for(int i = 0; str[i] != '\0' && str[i] != '\n'; i++)
    {
        stack[++top] = str[i];
    }
    printf("Reversed string: ");
    while(top != -1)
    {
        printf("%c", stack[top--]);
    }
    printf("\n");
    return 0;
}