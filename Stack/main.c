#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
#define ElemType char
#define BOOL int
#define TRUE 1
#define FALSE 0

typedef struct{
    int data[MAXSIZE];
    int top;    //ջ��ָ��
}Stack;

void InitStack(Stack *s);   //��ʼ��ջ
void Push(Stack *s, ElemType e);    //ѹջ����
void Pop(Stack *s, ElemType *e); //��ջ����
BOOL IsEmpty(Stack s);  //�Ƿ�Ϊ��

int main()
{
    Stack s;
    ElemType e;
    InitStack(&s);
    printf("%d\n", IsEmpty(s));
    Push(&s, 'a');
    Push(&s, 'b');
    Pop(&s, &e);
    printf("%c\n", e);
    printf("%d\n", IsEmpty(s));
    Pop(&s, &e);
    printf("%c\n", e);
    printf("%d\n", IsEmpty(s));
    return 0;
}

void InitStack(Stack *s){
    s->top = -1;
}

void Push(Stack *s, ElemType e){
    ++s->top;
    s->data[s->top] = e;
}

void Pop(Stack *s, ElemType *e){
    *e = s->data[s->top];
    --s->top;
}

BOOL IsEmpty(Stack s){
    if (s.top <= -1){
        return TRUE;
    }else{
        return FALSE;
    }
}
