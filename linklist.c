#include <stdio.h>
#include <stdlib.h>

//����ṹ�����Ͷ���
typedef struct linklist
{
    struct linklist *prior;
    struct linklist *next;

    int data;
}Linklist;

//��ʼ��������
Linklist *createlist(){
    //����ռ�
    Linklist *head = (Linklist *)malloc(sizeof(Linklist));
    Linklist *tail = (Linklist *)malloc(sizeof(Linklist));
    //ͷβ�ڵ��ʼ��
    head->prior = NULL;
    head->next = tail;
    head->data = 0;
    tail->prior = head;
    tail->next = NULL;
    tail->data = 0;
    
    return head;
}

//����ڵ�
void insertnode(Linklist *previousnode,int defaultvalue){
    if (previousnode->next==NULL)
        printf("no more space\n");
    else{
        Linklist *p = (Linklist *)malloc(sizeof(Linklist)),*r;

        r = previousnode->next;
        previousnode->next = p;
        p->prior = previousnode;
        p->next = r;
        r->prior = p;

        p->data = defaultvalue;
    }
}

//ɾ���ڵ�
void deletenode(Linklist *node){
    Linklist *p = node;
    p->prior->next = p->next;
    p->next->prior = p->prior;
    free(p);
}

//��ӡ����
void printlist(Linklist *head){
    Linklist *p;
    p=head->next;
    while (p->next!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}


int main(){
    Linklist *head = createlist();
    Linklist *p = head;
    int homo[] = {1,1,4,5,1,4,1,9,1,9,8,1,0};
    for(int i = 0;i < (sizeof(homo)/sizeof(int));i++){
        insertnode(p,homo[i]);
        p = p->next;
    }

    printlist(head);

    int serial_num;
    printf("select which node to delete:");
    scanf("%d",&serial_num);
    p = head;
    for(int i = 0;i < serial_num;i++){
        if(p->next->next == NULL){
            printf("wrong address\n");
            serial_num = 0;
            break;
        }
        else{
            p = p->next;
        }
    }
    if(serial_num)
        deletenode(p);

    printlist(head);
    return 0;
}