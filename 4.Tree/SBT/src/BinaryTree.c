#include "BinaryTree.h"

/* 노드 생성 */
SBTNode* SBT_CreateNode(ElementType NewData) {
	SBTNode* NewNode = (SBTNode*)malloc(sizeof(SBTNode));
	NewNode->Left = NULL;
	NewNode->Right = NULL;
	NewNode->Data = NewData;

	return NewNode;
}
/* 노드 해제 */
void SBT_DestroyNode(SBTNode* Node) {
	free(Node);
}
/* Tree 제거 */
// 후위순회를 이용하면 어떤트리던 문제없이 삭제할 수 있다.
void SBT_DestroyTree(SBTNode* Root) {
	if (Root == NULL) return;

	/* 왼쪽 하위 트리 소멸 */
	SBT_DestroyTree(Root->Left);
	/* 오른쪽 하위 트리 소멸 */
	SBT_DestroyTree(Root->Right);
	/* 루트노드 소멸 */
	SBT_DestroyNode(Root);
}

/* 전위순회 이진트리 출력 */
void SBT_PreorderPrintTree(SBTNode* Node) {
	if (Node == NULL) return;

	/* 루트노드 출력 */
	printf(" % c", Node->Data);
	/* 왼쪽 하위 트리 출력 */
	SBT_PreorderPrintTree(Node->Left);
	/* 오른쪽 하위 트리 출력 */
	SBT_PreorderPrintTree(Node->Right);
}
/* 중위순회 이진트리 출력 */
void SBT_InorderPrintTree(SBTNode* Node) {
	if (Node == NULL) return;

	/* 왼쪽 하위 트리 출력 */
	SBT_InorderPrintTree(Node->Left);
	/* 루트노드 출력 */
	printf(" % c", Node->Data);
	/* 오른쪽 하위 트리 출력 */
	SBT_InorderPrintTree(Node->Right);
}
/* 후위순회 이진트리 출력 */
void SBT_PostorderPirntTree(SBTNode* Node) {
	if (Node == NULL) return;

	/* 왼쪽 하위 트리 출력 */
	SBT_PostorderPirntTree(Node->Left);
	/* 오른쪽 하위 트리 출력 */
	SBT_PostorderPirntTree(Node->Right);
	/* 루트노드 출력 */
	printf(" % c", Node->Data);
}
