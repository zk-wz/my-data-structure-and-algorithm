#include <stdio.h>
#include <stdlib.h>

//���ӽڵ�
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

//��ʼ������
LinkQueue* InitQueue()
{
    LinkQueue *Q = (LinkQueue *)malloc(sizeof(LinkQueue));
    Q->front = Q->rear = NULL;
    return Q;
}

//�ж������Ƿ�Ϊ��
int Empty(LinkQueue *Q)
{
    if(Q->front == NULL)
        return 1;
    else
        return 0;
}

//���
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

//����
int DeQueue(LinkQueue *Q)
{
    QueueNode *p;
    int x;
    if(Empty(Q))
    {
        printf("�ӿ�");
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
    printf("����Ԫ��Ϊ��%d\n", DeQueue(Q));
    printf("������һ�����Ԫ�أ�\n");
    int x;
    scanf("%d", &x);
    EnQueue(Q, x);
    printf("�¶ӵ�ͷԪ��Ϊ:%d\n", Q->front->data);
    int flag = 1;
    while(flag)
    {
        printf("����Ԫ��Ϊ��%d\n", DeQueue(Q));
        if(Q->front == NULL)
            flag = 0;
    }
    return 0;
}
