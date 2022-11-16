#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
//����˳��ջ
typedef struct stack
{
    int top;
    char data[MAX];
}seqstack;

//��ʼ��ջ
seqstack* initstack()
{
    seqstack *s = (seqstack *)malloc(sizeof(seqstack));
    s->top = -1;
    return s;
}

//��ջ
void push(seqstack *s, char x)
{
    if(s->top == MAX-1)
    {
        printf("ջ��");
        return;
    }
    s->top++;
    s->data[s->top] = x;
}

//��ջ
char pop(seqstack *s)
{
    if(s->top == -1)
    {
        printf("ջ��");
        return 0;
    }
    char x = s->data[s->top];
    s->top--;
    return x;
}

//ȡջ��Ԫ��
char gettop(seqstack *s)
{
    if(s->top == -1)
    {
        printf("ջ��");
        return 0;
    }
    return s->data[s->top];
}

int correct(seqstack *s, char *str)
{
    for(int i = 0; i < strlen(str); i++){
        if(str[i] == '(' || str[i] == '[' || str[i] == '{')
            push(s, str[i]);
        else if(str[i] == ')'){
            if(gettop(s) == '(')
                pop(s);
            else
                return 0;
        }
        else if(str[i] == ']'){
            if(gettop(s) == '[')
                pop(s);
            else
                return 0;
        }
        else if(str[i] == '}'){
            if(gettop(s) == '{')
                pop(s);
            else
                return 0;
        }
    }
    return 1;
}


int main(){
    char a[] = "(((({{})))";
    seqstack *s = initstack();
    printf("%d",correct(s, a));
}
