#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "Graph.h"
#define MAXVEX 100 /* ��󶥵���,Ӧ���û����� */
typedef char VertexType; /* ��������Ӧ���û����� */
typedef int EdgeType; /* ���ϵ�Ȩֵ����Ӧ���û����� */

int visited[200];

typedef struct EdgeNode/* �߱���  */
{
    int adjvex;/* �ڽӵ���,�洢�ö����Ӧ���±� */
    EdgeType weight;/* ���ڴ洢Ȩֵ,���ڷ���ͼ���Բ���Ҫ */
    struct EdgeNode *next; /* ����,ָ����һ���ڽӵ� */
} EdgeNode;

typedef struct VextexNode/* ������� */
{
    VertexType data;/* ������,�洢������Ϣ */
    EdgeNode *firstedge;/* �߱�ͷָ�� */
} VextexNode, AdjList[MAXVEX];

typedef struct
{
    AdjList adjList;
    int numNodes, numEdges; /* ͼ�е�ǰ�������ͱ��� */
} GraphAdjList;

EdgeNode* FirstAdjVex(GraphAdjList graph, VertexType data);
EdgeNode* NextAdjVex(GraphAdjList graph, VertexType data, int adjvex);
void DFS(GraphAdjList graph, VertexType data);
void BFS(GraphAdjList graph, VertexType data);
void BFSTraverse(GraphAdjList graph);
int main()
{
    GraphAdjList graph;
    /*
    printf("�����붥����, ������");
    scanf("%d %d", &graph.numNodes, &graph.numEdges);
    getchar();
    */
    int i, j;
    /*
    for (i = 0; i < graph.numNodes; ++i){
        printf("�����붥�㣺");
        scanf("%c", &graph.adjList[i].data);
        getchar();  //�����հ׷�
        graph.adjList[i].firstedge = NULL;
    }
    */

  //  int i, j;
    graph.numNodes = 6;
    graph.numEdges = 6;
    graph.adjList[0].data = 'A';
    graph.adjList[0].firstedge = NULL;
    graph.adjList[1].data = 'B';
    graph.adjList[1].firstedge = NULL;
    graph.adjList[2].data = 'C';
    graph.adjList[2].firstedge = NULL;
    graph.adjList[3].data = 'D';
    graph.adjList[3].firstedge = NULL;
    graph.adjList[4].data = 'E';
    graph.adjList[4].firstedge = NULL;
    graph.adjList[5].data = 'F';
    graph.adjList[5].firstedge = NULL;
    //getchar();

    for (i = 0; i < graph.numEdges; ++i){
        printf("��������㣬 �յ㣺");
        char start, end;
        VextexNode* startNode;  //�ҳ���β��㣬��ͷ���
        scanf("%c %c", &start, &end);
        EdgeNode* newNode = (EdgeNode*)malloc(sizeof(EdgeNode));    //�����½ڵ�
        for (j = 0; j < graph.numNodes; ++j){
            if (graph.adjList[j].data == start){
                startNode = &graph.adjList[j];
            }
            if (graph.adjList[j].data == end){

                newNode->adjvex = j;
                newNode->next = NULL;
            }
        }
        EdgeNode* edgeNode = startNode->firstedge;
        if (edgeNode != NULL){
            while(edgeNode->next != NULL){    //ѭ�������һ�����
                edgeNode = edgeNode->next;
            }
            edgeNode->next = newNode;
        } else {
            startNode->firstedge = newNode;
        }
        getchar();
    }
    for (i = 0; i < graph.numEdges; ++i){
        printf("Vex:%c", graph.adjList[i].data);
        EdgeNode* edgeNode = graph.adjList[i].firstedge;
        if (edgeNode != NULL){
            printf(" ->Edge:%c", graph.adjList[edgeNode->adjvex].data);
            while(edgeNode->next != NULL){    //ѭ�������һ�����
                edgeNode = edgeNode->next;
                printf(" ->Edge:%c", graph.adjList[edgeNode->adjvex].data);
            }
        }
        printf("\n");
    }
    for (i = 0; i < 200; ++i){
        visited[i] = 0;
    }
    printf("DFS:");
    DFS(graph, graph.adjList[0].data);
    printf("\n-----------\n");
    for (i = 0; i < 200; ++i){
        visited[i] = 0;
    }
    printf("BFS:");
    BFS(graph, graph.adjList[0].data);
    return 0;
}

/*
    Ѱ�ҵ�һ���߽��
*/
EdgeNode* FirstAdjVex(GraphAdjList graph, VertexType data){
    int i;
    for (i = 0; i < graph.numNodes; ++i){
        if (graph.adjList[i].data == data){ //�ҵ����
            //printf("ccc ");
            return graph.adjList[i].firstedge;
        }
    }
    return NULL;
}

/*
    Ѱ����һ���߽��
*/
EdgeNode* NextAdjVex(GraphAdjList graph, VertexType data, int adjvex){
    int i;
    for (i = 0; i < graph.numNodes; ++i){
        if (graph.adjList[i].data == data){//�ҵ����
            EdgeNode* edgeNode = graph.adjList[i].firstedge; //�ҵ���һ���߽��
            while (edgeNode != NULL && edgeNode->adjvex != adjvex){
                edgeNode = edgeNode->next;
            }
            if (edgeNode != NULL){  //˵���ҵ�
                return edgeNode->next;
            } else {
                return NULL;
            }
        }
    }
    return NULL;
}

/*
    ��ȱ���
*/
void DFS(GraphAdjList graph, VertexType data){
    visited[data] = 1;
    printf("%c ", data);
    EdgeNode *p;
    for (p = FirstAdjVex(graph, data); p != NULL; p=NextAdjVex(graph, data, p->adjvex)){
        if (visited[graph.adjList[p->adjvex].data] != 1){    //û���ʹ�
            DFS(graph, graph.adjList[p->adjvex].data);
        }
    }
}

/*
    ��ȱ���
*/
void BFSTraverse(GraphAdjList graph){
    int i;
    BFS(graph, graph.adjList[0].data);
    /*
    for (i = 0; i < graph.numNodes; ++i){
        if (visited[graph.adjList[i].data] != 1){
            BFS(graph, graph.adjList[i].data);
        }
    }
    */
}

/*
    ��ȱ���
*/
void BFS(GraphAdjList graph, VertexType data){
    SqQueue queue;
    InitQueue(&queue);
    EnQueue(&queue, data);
    ElemType x;
    EdgeNode *p;
    visited[data] = 1;
    while (!QueueEmpty(&queue)){
        DeQueue(&queue, &x);
        printf("%c ", x);
        for (p = FirstAdjVex(graph, x); p != NULL; p=NextAdjVex(graph, x, p->adjvex)){
            if (visited[graph.adjList[p->adjvex].data] != 1){
                EnQueue(&queue, graph.adjList[p->adjvex].data);
                visited[graph.adjList[p->adjvex].data] = 1;
            }
        }
    }
}
