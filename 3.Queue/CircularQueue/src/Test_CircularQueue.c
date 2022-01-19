#include "CircularQueue.h"

int main(void) {
	int i;
	CircularQueue* Queue;

	CQ_CreateQueue(&Queue, 10);

	CQ_Enqueue(Queue, 1);
	CQ_Enqueue(Queue, 2);
	CQ_Enqueue(Queue, 3);
	CQ_Enqueue(Queue, 4);

	for (i = 0; i < 3; i++) {
		printf("Dequeque : %d\n", CQ_DeQueue(Queue));
		printf("Front: %d, Rear:%d\n", Queue->Front, Queue->Rear);
	}

	i = 100;
	while (CQ_IsFull(Queue) == 0) {
		CQ_Enqueue(Queue, i++);
	}

	printf("Capacity: %d, Size: %d\n\n", Queue->Capacity, CQ_GetSize(Queue));

	CQ_DestroyQueue(Queue);

	return 0;
}
