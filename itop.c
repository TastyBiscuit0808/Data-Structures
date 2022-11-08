#include<stdio.h>
#include<stdlib.h>

//      I  S
// +,-  1  2
// *,/  3  4
// $    5  6 
// operands  7  8
// )    0  Never pushed to stack  
// (    9  0
// #    -  -1

int input_prcd(char c)
{
    if(c =='+' || c == '-')
    {
        return 1;
    }
    if(c =='*' || c == '/')
    {
        return 3;
    }
    if(c == '$')
    {
        return 5;
    }
    if(c == '(')
    {
        return 9;
    }
    if(c == ')')
    {
        return  0;
    }
}

int stack_prcd(char c)
{
    if(c =='+' || c == '-')
    {
        return 2;
    }
    if(c =='*' || c == '/')
    {
        return 4;
    }
    if(c == '$')
    {
        return 6;
    }
    if(c == '(')
    {
        return 0;
    }
    if(c=='#')
    {
        return -1;
    }
}

void push(char *s,int *top, char ch)
{
    (*top)++;
    s[*top] = ch;
}

char pop(char *s,int *top) // we are changing the array, so top is passed as a pointer
{
    char c = s[*top];
    (*top)--;
    return c;
}

char peep(char *s,int top) 
{
    char c;
    c = s[top];
    return c;
}

void infix_to_postfix(char *infix, char *postfix)
{
    int i=0,j=0;
    int top = -1;
    char ch,s[100];
    push(s,&top,'#');
    while(infix[i]!='\0')
    {
        char ch = infix[i];
        while(stack_prcd(peep(s,top))>input_prcd(ch))
        {
            postfix[j++] = pop(s,&top);
        }
        if(stack_prcd(peep(s,top))!=input_prcd(ch))
        {
            push(s,&top,ch);
        }
        else
        {
            pop(s,&top);
        }
        i++;
    }
    while(peep(s,top)!='#')
    {
        postfix[j++] = pop(s,&top);
    }
    postfix[j] = '\0';
}

int main()
{
    char infix[100], postfix[100];
    printf("Enter valid infix expression : ");
    scanf("%s",&infix);
    infix_to_postfix(infix,postfix);
    printf("Infix to postfix expression is : %s",postfix);
}      

