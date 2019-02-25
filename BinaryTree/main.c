#include <stdio.h>

typedef struct BiTnode{
    char data;
    struct BiTnode *lchild, *rchild;
}*BiTree, BiTNode;

void PreOrder(BiTree T);	//ǰ�����
void InOrder(BiTree T);	//�������
void PostOrder(BiTree T);	//�������
void CreateBiTree(BiTree* T);	//������
int Depth(BiTree T);

int main() {
    BiTree T;
    CreateBiTree(&T);
    printf("PreOrder:");
    PreOrder(T);
    printf("\n");
    printf("InOrder:");
    InOrder(T);
    printf("\n");
    printf("PostOrder:");
    PostOrder(T);
    printf("\n");
    printf("Depth:%d", Depth(T));
    printf("\n");
    return 0;
}

void CreateBiTree(BiTree* T) {   //���������������
    char ch;
    if ((ch = getchar()) == '\n')
    {
        return;
    }
    if (ch == '#')
    {
        (*T) = NULL;
    }
    else
    {
        *T = (BiTNode *)malloc(sizeof(BiTNode));
        (*T)->data = ch;
        CreateBiTree(&((*T)->lchild)); //��ΪҪ����һ��(struct BiTnode *lchild)��ָ�룬Ҳ����ָ���ָ��
        CreateBiTree(&((*T)->rchild));
    }
}

void PreOrder(BiTree T) {
    if (T != NULL) {
        printf("%c ", T->data);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

void InOrder(BiTree T) {
    if (T != NULL) {
        InOrder(T->lchild);
        printf("%c ", T->data);
        InOrder(T->rchild);
    }
}

void PostOrder(BiTree T) {
    if (T != NULL) {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        printf("%c ", T->data);
    }
}

int Depth(BiTree T) {
    if(T == NULL) {
        return 0;
    } else {
        int m = Depth(T->lchild);
        int n = Depth(T->rchild);
        if (m > n) {
            return (m+1);
        }
        else {
            return (n+1);
        }
    }
}
