#include <stdio.h>
#include <string.h>
void InfixToPostfix(char infix[], int bool[], int left, int right, char a, char b)
{
    while (left <= right)
    {
        if ((infix[left] == a || infix[left] == b) && bool[left] == 0)
        {
            int m = left;
            bool[left] = 1;
            char temp = infix[left];
            while (bool[m + 1] != 0)
            {
                infix[m] = infix[m + 1];
                m++;
            }
            infix[m] = temp;
        }
        left++;
    }
}
int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
    {
        return 1;
    }
    return 0;
}
void main()
{
    char infix[30];
    int bool[30], left, right;
    int i = 0;
    printf("Enter a string : ");
    scanf(" %[^\n]", infix);
    int n = strlen(infix);
    for (i = n - 1; i >= 0; i--)
    {
        infix[i + 1] = infix[i];
    }
    infix[0] = '(';
    infix[n + 1] = ')';
    infix[n + 2] = '\0';
    bool[n + 2] = 0;
    i = 0;
    while (infix[i] != '\0')
    {
        if (isOperator(infix[i]) || infix[i] == '(' || infix[i] == ')')
        {
            bool[i] = 0;
        }
        else
        {
            bool[i] = 1;
        }
        i++;
    }
    i = 0;
    while (i < n + 2)
    {
        if (infix[i] == ')' && bool[i] == 0)
        {
            left = right = i;
            while (infix[left] != '(' || bool[left] != 0)
                left--;
            InfixToPostfix(infix, bool, left + 1, right, '^', '^');
            InfixToPostfix(infix, bool, left + 1, right, '*', '/');
            InfixToPostfix(infix, bool, left + 1, right, '+', '-');
            bool[right] = 1;
            bool[left] = 1;
        }
        i++;
    }
    printf("Postfix is ");
    for (i = 0; i < n + 2; i++)
    {
        if (infix[i] != '(' && infix[i] != ')')
        {
            printf("%c", infix[i]);
        }
    }
    printf("\n");
}