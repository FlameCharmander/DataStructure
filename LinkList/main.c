#include <stdio.h>
#include <stdlib.h>

typedef char ElemType;
typedef int BOOL;
#define TRUE 1
#define FALSE 0

typedef struct LinkNode{
    ElemType data;
    struct LinkNode* next;
}LinkList, Node;

void InitList(LinkList *list);   //��ʼ������
BOOL Insert(LinkList *list, ElemType e, int pos);   //��Ԫ�ز���
BOOL Delete(LinkList *list, ElemType e);    //��ָ��Ԫ��ɾ��
BOOL IsEmtpy(LinkList *list);   //�ж������Ƿ�Ϊ��

int main()
{
    LinkList list;
    InitList(&list);
    printf("%d\n", IsEmtpy(&list));
    Insert(&list, 'a', 1);
    Insert(&list, 'b', 2);
    Insert(&list, 'c', 1);
    Delete(&list, 'a');
    Node *p = list.next;
    while (p != NULL) {
        printf("%c ", p->data);
        p = p->next;
    }
    printf("\n%d\n", IsEmtpy(&list));
    Delete(&list, 'b');
    Delete(&list, 'c');
    printf("%d\n", IsEmtpy(&list));
    return 0;
}

void InitList(LinkList *list){
    list->next = NULL; //����һ��ͷ���
}

BOOL Insert(LinkList *list, ElemType e, int pos){
    int i;
    Node* pre = list;
    for (i = 1; i < pos; ++i){
        pre = pre->next;
    }
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = e;
    node->next = pre->next;
    pre->next = node;
    return TRUE;
}

BOOL Delete(LinkList *list, ElemType e){
    Node* pre = list;
    while (pre->next != NULL) {
        if (pre->next->data == e){
            Node* q = pre->next;    //��ʱ�洢
            pre->next = pre->next->next;
            free(q);
            return TRUE;
        } else {
            pre = pre->next;
        }
    }
    return FALSE;
}

BOOL IsEmtpy(LinkList *list){
    if (list->next == NULL) {
        return TRUE;
    } else {
        return FALSE;
    }
}
