#include "BinarySearch.h"

int main(void) {
	// 노드생성
	BSTNode* Tree = BST_CreateNode(123);
	BSTNode* Node = NULL;

	// 트리에 노드 추가
	BSTNode_InsertNode(&Tree, BST_CreateNode(22));
	BSTNode_InsertNode(&Tree, BST_CreateNode(9918));
	BSTNode_InsertNode(&Tree, BST_CreateNode(424));
	BSTNode_InsertNode(&Tree, BST_CreateNode(17));
	BSTNode_InsertNode(&Tree, BST_CreateNode(3));

	BSTNode_InsertNode(&Tree, BST_CreateNode(98));
	BSTNode_InsertNode(&Tree, BST_CreateNode(34));

	BSTNode_InsertNode(&Tree, BST_CreateNode(760));
	BSTNode_InsertNode(&Tree, BST_CreateNode(317));
	BSTNode_InsertNode(&Tree, BST_CreateNode(1));

	// 트리출력
	BSTNode_InorderPrintTree(Tree);

	// 특정 노드 삭제
	printf("Removing 98 .. \n");

	Node = BSTNode_RemoveNode(Tree, NULL, 98);
	BST_DestroyNode(Node);

	BSTNode_InorderPrintTree(Tree);
	printf("\n");

	// 새노드 삽입
	printf("Inserting 111 ...\n");

	BSTNode_InsertNode(&Tree, BST_CreateNode(111));
	BSTNode_InorderPrintTree(Tree);
	printf("\n");

	// 트리 소멸 시키기
	BST_DestroyTree(Tree);

	return 0;
}
