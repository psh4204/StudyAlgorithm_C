#include "CircularDoublyLinkdeList.h"

/* Node 생성 */
Node* CDLL_CreateNode(ElementType NewData) {
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Data = NewData;
	NewNode->PrevNode = NULL;
	NewNode->NextNode = NULL;

	return NewNode;
}

/* 노드 소멸 */
void CDLL_DestroyNode(Node* Node) {
	free(Node);
}

/* 노드 추가 */
void CDLL_AppendNode(Node** Head, Node* NewNode) {
	/* 헤드 노드가 NULL 이라면 새로운 노드가 Head */
	if ((*Head) == NULL) {
		*Head = NewNode;
		(*Head)->NextNode = *Head;
		(*Head)->PrevNode = *Head;
	}
	else
	{
		/* 테일을 찾아 NewNode를 연결한다.*/
		// 테일과 헤드사이에 노드를 추가한다.
		Node* Tail = (*Head)->PrevNode; // 커서역할을 한다.

		// 꼬리노드의 다다음 노드의 이전노드를 새노드로
		Tail->NextNode->PrevNode = NewNode;
		Tail->NextNode = NewNode;
		NewNode->NextNode = (*Head);
		NewNode->PrevNode = Tail; // 기존 노드에 앞노드를 새노드로 만든다.

	}
}

/* 노드삽입 */
void CDLL_InsertAfter(Node* Current, Node* NewNode) {
	NewNode->NextNode = Current->NextNode;
	NewNode->PrevNode = Current;

	Current->NextNode->PrevNode = NewNode;
	Current->NextNode = NewNode;
}
/* 노드제거 */
void CDLL_RemoveNode(Node** Head, Node* Remove) {
	// 헤드노드가 삭제할 노드라면
	if (*Head == Remove) {
		// 헤드노드의 다음노드 설정, 꼬리노드 설정을 해줘야한다.
		(*Head)->PrevNode->NextNode = Remove->NextNode;
		(*Head)->NextNode->PrevNode = Remove->PrevNode;

		// 다음 노드를 헤드로
		*Head = Remove->NextNode;

		// 삭제한 노드의 앞뒤 노드주소들을 비워준다.
		Remove->PrevNode = NULL;
		Remove->NextNode = NULL;
	}

	else {
		Node* Temp = Remove;
		Remove->PrevNode->NextNode = Temp->NextNode;
		
		Remove->PrevNode->NextNode = Temp->NextNode;
		Remove->NextNode->PrevNode = Temp->PrevNode;

		Remove->PrevNode = NULL;
		Remove->NextNode = NULL;
	}
}

/* 노드 탐색 */
Node* CDLL_GetNodeAt(Node* Head, int Location) {
	Node* Current = Head;

	while (Current != Head && (--Location) >= 0) {
		Current = Current->NextNode;
	}
	return Current;
}

/* 노드 수 확인 */
int CDLL_GetNodeCount(Node* Head) {
	int Count = 0;
	Node* Current = Head;
	// 카운트 세서 리턴
	do {
		Current = Current->NextNode;
		Count++;
	} while (Current != Head);
	return Count;
}
