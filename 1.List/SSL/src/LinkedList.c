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
}

/* 노드 삽입 */
void SSL_InsertAfter(Node* Current, Node* NewNode);

void SSL_InsertNewHead(Node** Head, Node* NewHead);

/* 노드 제거 */
void SSL_RemoveNodeAt(Node* Head, int Location);

/* 노드 수 세기 */
int SSL_GetNodeCount(Node* Head);
