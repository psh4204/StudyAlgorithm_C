#include "LinkdeQueue.h"

/* 링크드 큐 생성 */
void LQ_CreateQueue(LinkedQueue** Queue) {
	(*Queue)		= (LinkedQueue*)malloc(sizeof(LinkedQueue));
	(*Queue)->Front	= NULL;
	(*Queue)->Rear	= NULL;
	(*Queue)->Count	= NULL;
}
/* 링크드 큐 제거 */
void LQ_DestroyQueue(LinkedQueue* Queue) {
	while (!LQ_IsEmpty(Queue)) {
		Node* Popped = LQ_Dequeue(Queue);
		LQ_DestroyNode(Popped);
	}
	/* 큐를 자유 저장소에서 해제 */
	free(Queue);
}


Node * LQ_CreateNode(char* NewData) {
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Data = (char*)malloc(sizeof(NewData) + 1); // 문자열이어서 +1_Null

	strcpy(NewNode->Data, NewData); // 데이터를 저장한다.

	NewNode->NextNode = NULL;

	return NewNode;
}
void LQ_DestoryNode(Node* _Node) {
	free(_Node->Data);
	free(_Node);
}

/* 큐 삽입 */
void LQ_Enqueue(LinkedQueue* Queue, Node* NewNode) {
	// 비어있는 큐일경우 전단,앞단 자신으로 표시
	if (Queue->Front == NULL) {
		Queue->Front = NewNode;
		Queue->Rear = NewNode;
		Queue->Count++;
	}
	// 후단의 다음노드를 새노드로,
	// 큐의 후단을 책임지는 친구를 새 노드로
	else {
		Queue->Rear->NextNode = NewNode;
		Queue->Rear = NewNode;
		Queue->Count++;
	}
}
/* 제거 연산 */
Node* LQ_Dequeue(LinkedQueue* Queue) {
	//LQ_Dequeue 함수가 반환할 최상위 노드
	Node* Front = Queue->Front;

	// 삭제할 전단의 다음노드가 없을시
	if (Queue->Front->NextNode == NULL) {
		Queue->Front = NULL;
		Queue->Rear = NULL;
	}
	// 아니면 전단 다음 노드를 전단으로
	else {
		Queue->Front = Queue->Front->NextNode;
	}
	Queue->Count--; // Count 깎고
	return Front; // 전단 리턴
}

int LQ_IsEmpty(LinkedQueue* Queue) {
	return (Queue->Front == NULL);
}
