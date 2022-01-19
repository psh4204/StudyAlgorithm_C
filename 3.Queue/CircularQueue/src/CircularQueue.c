#include "CircularQueue.h"

/* 큐 생성 */
void CQ_CreateQueue(CircularQueue** Queue, int Capacity) {
	// 큐생성
	(*Queue) = (CircularQueue*)malloc(sizeof(CircularQueue));
	// 큐 배열 생성 + 1 (더미 노드_가득찼는지 확인용 노드)
	(*Queue)->Nodes = (Node*)malloc(sizeof(Node)*(Capacity+1));
	
	(*Queue)->Capacity = Capacity;	// 큐의 실제 저장용량
	(*Queue)->Front = 0;			// 전단
	(*Queue)->Rear = 0;				// 후단
}
/* 큐 제거 */
void CQ_DestroyQueue(CircularQueue* Queue) {
	free(Queue->Nodes);
	free(Queue);
}
/* 삽입 */
void CQ_Enqueue(CircularQueue* Queue, ElementType data) {
	int Position = 0;
	// 후단위치와 실제 Capacity크기 값과 같다면, 끝에 도달했다는 뜻.
	if (Queue->Rear == Queue->Capacity) {
		Position = Queue->Rear;
		Queue->Rear = 0;
	}
	else{
		Position = Queue->Rear++;
	}
	Queue->Nodes[Position].Data = data;
}
/* 제거 */
ElementType CQ_DeQueue(CircularQueue* Queue) {
	int Position = Queue->Front;
	// 제거할 전단의 위치가 용량위치라면 앞으로 다시 0으로(앞으로)옮겨준다.
	if (Queue->Front == Queue->Capacity) {
		Queue->Front = 0;
	}
	else
		Queue->Front++;

	return Queue->Nodes[Position].Data;
}
/* 크기 확인 */
int CQ_GetSize(CircularQueue* Queue) {
	if (Queue->Front <= Queue->Rear) {
		return Queue->Rear - Queue->Front;
	}
	else {
		return Queue->Rear + (Queue->Capacity - Queue->Front) + 1;
	}
}
/* 비었는지 보기 */
int CQ_IsEmpty(CircularQueue* Queue) {
	// 전단의 위치와 후단의 위치를 대입하여 확인
	return (Queue->Front == Queue->Rear);
}
/* 꽉찼는지 확인 */
int CQ_IsFull(CircularQueue* Queue) {
	// 후단이 전단보다 뒤에 있으면 (정상), 전단-후단의 값확인
	if (Queue->Front < Queue->Rear) {
		return (Queue->Rear - Queue->Front) == Queue->Capacity;
	}
	// 후단이 전단보다 앞에 있으면, 전단과 후단+1의 값 확인
	else {
		return (Queue->Rear+1) == Queue->Front;
	}
}
