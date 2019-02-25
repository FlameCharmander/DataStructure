#include <stdio.h>
#include <stdlib.h>

#define SIZE 100
#define INCREMENT 50

typedef int BOOL;
#define TRUE 1
#define FALSE 0
typedef char ElemType;

typedef struct{
    ElemType data[SIZE]; //Ԫ������
    int length; //����
    int capacity;   //����
}SqList;

void InitList(SqList* list); //��ʼ��˳���
BOOL Insert(SqList* list, ElemType e, int i);   //����
BOOL Delete(SqList* list, ElemType e);   //ɾ��
BOOL IsEmpty(SqList* list);  //�ж�Ϊ��

int main()
{
    SqList list;
    InitList(&list);
    printf("%d\n", IsEmpty(&list));
    Insert(&list, 'a', 1);
    printf("%d\n", IsEmpty(&list));
    Delete(&list, 'b');
    printf("%d\n", IsEmpty(&list));
    Delete(&list, 'a');
    printf("%d\n", IsEmpty(&list));
    return 0;
}

void InitList(SqList* list){
    list->length = 0;
    list->capacity = SIZE;
}

BOOL Insert(SqList* list, ElemType e, int pos){   //i�ķ�Χ1<=pos<=n
    int i;
    ++list->length;
    for (i = list->length; i > pos-1; --i){
        list->data[list->length] = list->data[list->length-1];
    }
    list->data[pos-1] = e;
    return TRUE;
}

BOOL Delete(SqList* list, ElemType e){
    int i, j;
    for (i = 0; i < list->length; ++i){
        if (list->data[i] == e){    //�ҵ���Ԫ��
            for (j = i; j < list->length; ++j){
                list->data[j] = list->data[j+1];
                --list->length;
                return TRUE;
            }
        }
    }
    return FALSE;
}

BOOL IsEmpty(SqList* list){
    if (list->length == 0) {
        return TRUE;
    } else {
        return FALSE;
    }
}
