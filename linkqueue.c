#include <stdio.h>
#include <stdlib.h>

//链队节点
typedef struct node
{
    int data;
    struct node *next;
}QueueNode;

typedef struct
{
    QueueNode *front;
    QueueNode *rear;
}LinkQueue;

//初始化链队
LinkQueue* InitQueue()
{
    LinkQueue *Q = (LinkQueue *)malloc(sizeof(LinkQueue));
    Q->front = Q->rear = NULL;
    return Q;
}

//判断链队是否为空
int Empty(LinkQueue *Q)
{
    if(Q->front == NULL)
        return 1;
    else
        return 0;
}

//入队
void EnQueue(LinkQueue *Q, int x)
{
    QueueNode *p = (QueueNode *)malloc(sizeof(QueueNode));
    p->data = x;
    p->next = NULL;
    if(Q->rear == NULL)
        Q->front = Q->rear = p;
    else
    {
        Q->rear->next = p;
        Q->rear = p;
    }
}

//出队
int DeQueue(LinkQueue *Q)
{
    QueueNode *p;
    int x;
    if(Empty(Q))
    {
        printf("队空");
        return 0;
    }
    else
    {
        p = Q->front;
        x = p->data;
        Q->front = p->next;
        if(Q->front == NULL)
            Q->rear = NULL;
        free(p);
        return x;
    }
}

int main()
{
    LinkQueue *Q = InitQueue();
    int a[] = {1,2,34,5,6,3,5,67,2,9};
    for(int i = 0; i < (sizeof(a)/sizeof(int)); i++)
        EnQueue(Q, a[i]);
    printf("出队元素为：%d\n", DeQueue(Q));
    printf("请输入一个入队元素：\n");
    int x;
    scanf("%d", &x);
    EnQueue(Q, x);
    printf("新队的头元素为:%d\n", Q->front->data);
    int flag = 1;
    while(flag)
    {
        printf("出队元素为：%d\n", DeQueue(Q));
        if(Q->front == NULL)
            flag = 0;
    }
    return 0;
}
