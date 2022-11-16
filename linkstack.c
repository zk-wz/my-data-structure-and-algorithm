#include <stdio.h>
#include <stdlib.h>


//链栈节点
typedef struct node
{
    int data;
    struct node *next;
}StackNode;

typedef struct
{
    StackNode *top;
}LinkStack;

//初始化链栈
LinkStack* InitStack()
{
    LinkStack *S = (LinkStack *)malloc(sizeof(LinkStack));
    S->top = NULL;
    return S;
}

//判断链栈是否为空
int Empty(LinkStack *S)
{
    if(S->top == NULL)
        return 1;
    else
        return 0;
}

//入栈
void Push(LinkStack *S, int x)
{
    StackNode *p = (StackNode *)malloc(sizeof(StackNode));
    p->data = x;
    p->next = S->top;
    S->top = p;
}

//出栈
int Pop(LinkStack *S)
{
    StackNode *p;
    int x;
    if(Empty(S))
    {
        printf("栈空");
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

//进制转换
void Converse()
{
    LinkStack *S;
    int n, m;
    S = InitStack();
    printf("请输入要转换的十进制数：\n");
    scanf("%d", &n);
    printf("请输入要转换的进制数：\n");
    scanf("%d", &m);
    while(n)
    {
        Push(S, n % m);
        n = n / m;
    }
    printf("转换后的数为：");
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
