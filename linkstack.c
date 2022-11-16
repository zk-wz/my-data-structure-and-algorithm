#include <stdio.h>
#include <stdlib.h>


//��ջ�ڵ�
typedef struct node
{
    int data;
    struct node *next;
}StackNode;

typedef struct
{
    StackNode *top;
}LinkStack;

//��ʼ����ջ
LinkStack* InitStack()
{
    LinkStack *S = (LinkStack *)malloc(sizeof(LinkStack));
    S->top = NULL;
    return S;
}

//�ж���ջ�Ƿ�Ϊ��
int Empty(LinkStack *S)
{
    if(S->top == NULL)
        return 1;
    else
        return 0;
}

//��ջ
void Push(LinkStack *S, int x)
{
    StackNode *p = (StackNode *)malloc(sizeof(StackNode));
    p->data = x;
    p->next = S->top;
    S->top = p;
}

//��ջ
int Pop(LinkStack *S)
{
    StackNode *p;
    int x;
    if(Empty(S))
    {
        printf("ջ��");
        return 0;
    }
    else
    {
        p = S->top;
        x = p->data;
        S->top = p->next;
        free(p);
        return x;
    }
}

//����ת��
void Converse()
{
    LinkStack *S;
    int n, m;
    S = InitStack();
    printf("������Ҫת����ʮ��������\n");
    scanf("%d", &n);
    printf("������Ҫת���Ľ�������\n");
    scanf("%d", &m);
    while(n)
    {
        Push(S, n % m);
        n = n / m;
    }
    printf("ת�������Ϊ��");
    while(!Empty(S))
    {
        printf("%d", Pop(S));
    }
    printf("\n");
}


int main(){
    Converse();
    return 0;
}
