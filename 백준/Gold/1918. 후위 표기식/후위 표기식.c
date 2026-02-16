#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    char data;
    int prior;
    struct node* next;
    struct node* prev;
}node;

int priority(char a)
{
    if(a=='(' || a==')') return 0;
    if(a=='*' || a=='/') return 2;
    if(a=='+' || a=='-') return 1;
}

node* push(node* stack, char a)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = a;
    newNode->prior = priority(a);
    newNode->next = NULL;
    newNode->prev = NULL;
    if(stack==NULL)
    {
        stack=newNode;
    }
    else
    {
        stack->next = newNode;
        newNode->prev = stack;
    }
    return newNode;
}

node* pop(node* stack)
{
    printf("%c",stack->data);
    node* tmp = stack->prev;
    if(tmp) tmp->next = NULL;
    free(stack);
    return tmp;
}

int main()
{
    node* stack = NULL;
    node* cur = stack;
    char eq[101];
    scanf("%s",eq);
    for(int i=0; eq[i]!='\0'; i++)
    {
        if(eq[i]>='A'&&eq[i]<='Z') printf("%c",eq[i]);
        else if(eq[i]=='(') cur=push(cur,eq[i]);
        else if(eq[i]==')')
        {
            while(cur->data!='(')
            {
                cur=pop(cur);
            }
            node* tmp = cur;
            cur = cur->prev;
            free(tmp);
        }
        else
        {
            while(cur && cur->prior>=priority(eq[i]))
            {
                cur=pop(cur);
            }
            cur=push(cur,eq[i]);
        }
    }
    while(cur) cur=pop(cur);
    return 0;
}