#include "LinkedList.h"

/* 노드 생성 */
Node* SSL_CreateNode(ElementType NewData) {
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Data = NewData;
	NewNode->NextNode = NULL;

	return NewNode;
}

/* 노드 소멸 */
void SSL_DestroyNode(Node* Node) {
	free(Node);
}

/* 노드 추가 */
// - 노드 헤드의 주소값이 NULL이면 NewNode의 값이 노드헤드가 된다.
// - 아니라면 리스트의 맨뒤에 노드가 추가된다.
void SSL_AppendNode(Node** Head, Node* NewNode) {
	/* 헤드 노드가 NULL 이라면 새로운 노드가 Head */
	if ((*Head) == NULL) {
		*Head = NewNode;
	}
	else
	{
		/* 테일을 찾아 NewNode를 연결한다.*/
		Node* Tail = (*Head); // 커서역할을 한다.
		while (Tail->NextNode != NULL) {
			Tail = Tail->NextNode;
		}
		Tail->NextNode = NewNode;
	}
}

/* 노드 삽입 */
void SSL_InsertAfter(Node* Current, Node* NewNode) {
	// 현재 노드에 뒤에 노드 삽입
	NewNode->NextNode = Current->NextNode;
	Current->NextNode = NewNode;
}

void SSL_InsertNewHead(Node** Head, Node* NewHead) {
	// 헤드 노드가 없으면 그냥 삽입
	if (*Head == NULL) {
		(*Head) = NewHead;
	}
	// 헤드노드가 존재하면 헤드노드 앞에 삽입
	else {
		NewHead->NextNode = (*Head);
		(*Head) = NewHead;
	}
}

/* 노드 제거 */
void SSL_RemoveNode(Node** Head, Node * Remove) {
	// 헤드노드가 삭제할 노드라면,(확실하게) NULL
	if (*Head == Remove) {
		*Head = Remove->NextNode;
	}
	else
	{
		Node* Current = *Head; // 커서를 헤드로 두고 시작
		// 삭제할 노드의 앞노드 찾기
		while (Current != NULL && Current->NextNode != Remove) {
			Current = Current->NextNode;
		}
		// 삭제할 노드의 앞노드의 다음노드를
		// 삭제할 노드의 다음노드로 바꿔준다.(삭제)
		if (Current != NULL) {
			Current->NextNode = Remove->NextNode;
		}
	}
}

// N번째 노드를 리턴하는 함수
Node* SSL_GetNodeAt(Node* Head, int Location) {
	Node* Current = Head;
	
	while (Current != NULL && (--Location) >= 0) {
		Current = Current->NextNode;
	}
	return Current;
}
/* 노드 수 세기 */
int SSL_GetNodeCount(Node* Head) {
	int Count = 0;
	Node* Current = Head;
	// 카운트 세서 리턴
	while (Current != NULL) {
		Current = Current->NextNode;
		Count++;
	}
	return Count;
}
