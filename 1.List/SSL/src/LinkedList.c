#include "LinkedList.h"

/* ��� ���� */
Node* SSL_CreateNode(ElementType NewData) {
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Data = NewData;
	NewNode->NextNode = NULL;

	return NewNode;
}

/* ��� �Ҹ� */
void SSL_DestroyNode(Node* Node) {
	free(Node);
}

/* ��� �߰� */
// - ��� ����� �ּҰ��� NULL�̸� NewNode�� ���� �����尡 �ȴ�.
// - �ƴ϶�� ����Ʈ�� �ǵڿ� ��尡 �߰��ȴ�.
void SSL_AppendNode(Node** Head, Node* NewNode) {
	/* ��� ��尡 NULL �̶�� ���ο� ��尡 Head */
	if ((*Head) == NULL) {
		*Head = NewNode;
	}
	else
}

/* ��� ���� */
void SSL_InsertAfter(Node* Current, Node* NewNode);

void SSL_InsertNewHead(Node** Head, Node* NewHead);

/* ��� ���� */
void SSL_RemoveNodeAt(Node* Head, int Location);

/* ��� �� ���� */
int SSL_GetNodeCount(Node* Head);
