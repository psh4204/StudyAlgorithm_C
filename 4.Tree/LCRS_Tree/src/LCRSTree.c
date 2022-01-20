#include "LSRSTree.h"

// 생성
LCRSNode* LCRS_CreateNode(ElementType NewData) {
	LCRSNode* NewNode = (LCRSNode*)malloc(sizeof(LCRSNode));
	NewNode->LeftChild = NULL;
	NewNode->RightSibling = NULL;
	NewNode->Data = NewData;
}
// 제거
void LCRS_DestroyNode(LCRSNode* Node) {
	free(Node);
}
// 
void LCRS_DestroyTree(LCRSNode* Root) {
	// 재귀함수
	// - 형재노드에 들어간다.
	if (Root->RightSibling != NULL) {
		LCRS_DestroyTree(Root->RightSibling);
	}
	// - 자식노드에 들어간다.
	if (Root->LeftChild != NULL) {
		LCRS_DestroyTree(Root->LeftChild);
	}

	Root->LeftChild = NULL;
	Root->RightSibling = NULL;

	LCRS_DestroyNode(Root);
}
// 해당 노드의 자식 추가
void LCRS_AddChildNode(LCRSNode* ParentNode, LCRSNode* ChildNode) {
	// 왼쪽 자식 없으면 바로 추가
	if (ParentNode->LeftChild == NULL) {
		ParentNode->LeftChild = ChildNode;
	}
	else
	{
		LCRSNode* TempNode = ParentNode->LeftChild;
		while (TempNode->RightSibling != NULL) {
			TempNode = TempNode->RightSibling;
		}
		TempNode->RightSibling = ChildNode;
	}
}
// 들여쓰기 트리 출력
void LCRS_PrintTree(LCRSNode* Node, int Depth) {
	int i = 0;

	/* 깊이 만큼 들여쓰기 한다. */
	for (i = 0; i < Depth; i++) {
		printf(" ");
	}
	/* 노드에 담긴 데이터를 출력한다. */
	printf("%c\n", Node->Data);

	// 재귀문으로 함수 호출
	// - 자식부터 출력
	if (Node->LeftChild != NULL) {
		LCRS_PrintTree(Node->LeftChild, Depth + 1);
	}
	// - 형제 출력
	if (Node->RightSibling != NULL) {
		LCRS_PrintTree(Node->RightSibling, Depth);
	}
}
