#ifndef HEAP_H
#define HEAP_H

#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagHeapNode{
    ElementType Data;
} HeapNode;

typedef struct tagHeaep{
    HeapNode* Nodes;
    int Capacity;
    int UseSize;
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
