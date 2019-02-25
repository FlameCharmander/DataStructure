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

static void InitStack(Stack *s);   //��ʼ��ջ
static void Push(Stack *s, ElemType e);    //ѹջ����
static void Pop(Stack *s, ElemType *e); //��ջ����
static BOOL IsEmpty(Stack s);  //�Ƿ�Ϊ��

static void InitStack(Stack *s){
    s->top = -1;
}

static void Push(Stack *s, ElemType e){
    ++s->top;
    s->data[s->top] = e;
}

static void Pop(Stack *s, ElemType *e){
    *e = s->data[s->top];
    --s->top;
}

static BOOL IsEmpty(Stack s){
    if (s.top <= -1){
        return TRUE;
    }else{
        return FALSE;
    }
}
