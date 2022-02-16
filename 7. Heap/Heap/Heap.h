#ifndef HEAP_H
#define HEAP_H

#include <stdio.h>
#include <memory.h>     // 메모리 조작 라이브러리(realloc, memecpy, memset)
#include <stdlib.h>

typedef int ElementType;

typedef struct tagHeapNode{
    ElementType Data;
} HeapNode;

typedef struct tagHeaep{
    HeapNode* Nodes;
    int Capacity;       // 총 용량 ( 사용가능한 최대 요소 개수 )
    int UsedSize;       // 실제 힙에 들어간 요소 수 ( 사용  해버린 요소의 개수 )
} Heap;

Heap*   HEAP_Create(int InitSize);
void    HEAP_Destory(Heap * H);
void    HEAP_Insert(Heap* H, ElementType NewData);
void    HEAP_DeleteMin(Heap* H, HeapNode* Root);
int     HEAP_GetParent(int Index);
int     HEAP_GetLeftChild(int Index);
void    HEAP_SwapNodes(Heap* H, int Index1, int Index2);
void    HEAP_PrintNodes(Heap* H);

#endif
