#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H
typedef int ElementType;

#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode {
	ElementType Data;
} Node;

typedef struct tagCircularQueue {
	int Capacity;
	int Front;
	int Rear;
	Node* Nodes;
} CircularQueue;

void CQ_CreateQueue(CircularQueue** Queue, int Capacity);
void CQ_DestroyQueue(CircularQueue* Queue);
void CQ_Enqueue(CircularQueue* Queue, ElementType data);
ElementType CQ_DeQueue(CircularQueue* Queue);
void CQ_GetSize(CircularQueue* Queue, int Capacity);
void CQ_CreateQueue(CircularQueue* Queue, int Capacity);
void CQ_CreateQueue(CircularQueue* Queue, int Capacity);

#endif
