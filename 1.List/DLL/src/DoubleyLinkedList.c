#include "DoubleyLinkedList.h"

/* Node 생성 */
Node* DLL_CreateNode(ElementType NewData) {
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Data = NewData;
	NewNode->PrevNode = NULL;
	NewNode->NextNode = NULL;

	return NewNode;
}

/* 노드 소멸 */
void DLL_DestroyNode(Node* Node) {
	free(Node);
}

/* 노드 추가 */
void DLL_AppendNode(Node** Head, Node* NewNode) {
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
		// 더블 링크드 리스트 라서 이전 노드을 만져줘야한다.
		NewNode->PrevNode = Tail;
	}
}

/* 노드삽입 */
void DLL_InsertAfter(Node* Current, Node* NewNode) {
	NewNode->NextNode = Current->NextNode;
	NewNode->PrevNode = Current;

	if (Current->NextNode != NULL) {
		Current->NextNode->PrevNode = NewNode;
	}
	Current->NextNode = NewNode;
}
/* 노드제거 */
void DLL_RemoveNode(Node** Head, Node* Remove) {
	// 헤드노드가 삭제할 노드라면
	if (*Head == Remove) {
		// 다음 노드를 헤드로
		*Head = Remove->NextNode;
		// 헤드가 된 이 노드가 있다면, 이노드의 앞노드를 비워준다.
		if ((*Head) != NULL) { 
			(*Head)->PrevNode = NULL;
		}
		// 삭제한 노드의 앞뒤 노드주소들을 비워준다.
		Remove->PrevNode = NULL;
		Remove->NextNode = NULL;
	}

	else {
		Node* Temp = Remove;
		Remove->PrevNode->NextNode = Temp->NextNode;
		if (Remove->NextNode != NULL) {
			Remove->NextNode->PrevNode = Temp->PrevNode;
		}
		Remove->PrevNode = NULL;
		Remove->NextNode = NULL;
	}
}

/* 노드 탐색 */
Node* DLL_GetNodeAt(Node* Head, int Location) {
	Node* Current = Head;

	while (Current != NULL && (--Location) >= 0) {
		Current = Current->NextNode;
	}
	return Current;
}

/*  */
int DLL_GetNodeCount(Node* Head) {
	int Count = 0;
	Node* Current = Head;
	// 카운트 세서 리턴
	while (Current != NULL) {
		Current = Current->NextNode;
		Count++;
	}
	return Count;
}
