#include "BinarySearch.h"

BSTNode* BST_CreateNode(ElementType NewData) {
	BSTNode* NewNode = (BSTNode*)malloc(sizeof(BSTNode));
	NewNode->Left = NULL;
	NewNode->Right = NULL;
	NewNode->Data = NewData;

	return NewNode;
}
void BST_DestroyNode(BSTNode* Node) {
	free(Node);
}
void BST_DetroyTree(BSTNode* Tree) {
	if (Tree->Right != NULL) {
		BST_DestroyTree(Tree->Right);
	}
	if (Tree->Left != NULL) {
		BST_DestroyTree(Tree->Left);
	}
	Tree->Left = NULL;
	Tree->Right = NULL;

	BST_DestroyNode(Tree);
}

// 이진탐색 함수
// - 찾는 값이 작으면 왼쪽, 크면 오른쪽 자식노드로 움직인다.
BSTNode* BSTNode_SearchNode(BSTNode* Tree, ElementType Target) {
	if (Tree == NULL) {
		return NULL;
	}
	// 값을 찾으면 Return
	if (Tree->Data == Target) {
		return Tree;
	}
	// 값이 현재노드보다 작으면 왼쪽 노드로
	else if (Tree->Data > Target) {
		return BSTNode_SearchNode(Tree->Left, Target);
	}
	// 값이 현재노드보다 크면 오른쪽 노드로
	else {
		return BSTNode_SearchNode(Tree->Right, Target);
	}
}

// 최소값 노드 탐색 함수 
// - 오른쪽자식의 가장왼쪽자식을 찾는 함수
BSTNode* BSTNode_SearchMinNode(BSTNode* Tree) {
	if (Tree == NULL) {
		return NULL;
	}
	if (Tree->Left == NULL) {
		return Tree;
	}
	else {
		return BST_SearchMinNode(Tree->Left);
	}
}

// 노드 삽입
// - 넣을 값이 작으면 왼쪽, 크면 오른쪽 자식노드로 움직인다.
void BSTNode_InsertNode(BSTNode** Tree, BSTNode* Child) {
	// 넣을 자식노드가 크면 오른쪽 자식노드로
	if ((*Tree)->Data < Child->Data) {
		if ((*Tree)->Right == NULL) {
			(*Tree)->Right = Child;
		}
		else
			BSTNode_InsertNode(&(*Tree)->Right, Child);
	}
	// 넣을 자식노드가 작으면 왼쪽 자식노드로
	else if ((*Tree)->Data > Child->Data) {
		if ((*Tree)->Left == NULL) {
			(*Tree)->Left = Child;
		}
		else
			BSTNode_InsertNode(&(*Tree)->Left, Child);
	}
}

// 노드 삭제 함수
// * 삭제할 노드의 3가지 경우를 떠올려야한다.
// (* 무자식, 외자식, 양자식)
// - 무자식 : 해당노드 NULL 처리
// - 외자식 : 해당노드 자식을 해당노드로
// - 양자식 : 해당노드 자식의 최소값 노드( 오른쪽 자식노드의 최소값 노드) 를 해당노드로,
//				최소값 노드의 자식을 최소값 노드 로.
BSTNode* BSTNode_RemoveNode(BSTNode* Tree, BSTNode* Parent, ElementType Target) {
	BSTNode* Removed = NULL;
	if (Tree == NULL) {
		return NULL;
	}
	// 타겟이 더 작으면 왼쪽자식으로
	if (Tree->Data > Target) {
		Removed = BSTNode_RemoveNode(Tree->Left, Tree, Target);
	}
	// 타겟이 더 크면 오른쪽 자식으로
	else if (Tree->Data < Target) {
		Removed = BSTNode_RemoveNode(Tree->Right, Tree, Target);
	}
	else // 목표값을 찾은 경우
	{
		Removed = Tree;

		// 잎노드 인 경우 삭제(무자식)
		if (Tree->Left == NULL && Tree->Right == NULL) {
			if (Parent->Left == Tree)
				Parent->Left = NULL;
			else
				Parent->Right = NULL;
		}
		// 처리가 필요한 친구들(양자식, 외자식)
		else
		{
			// 양자식
			if (Tree->Left != NULL && Tree->Right != NULL) {
				// 최소값 노드를 찾아 제거한 뒤 현재 노드에 위치 시킨다.
				BSTNode* MinNode = BSTNode_SearchMinNode(Tree->Right);
				// 최소값 노드에 관한 삭제처리
				Removed = BSTNode_RemoveNode(Tree, NULL, MinNode->Data);
				Tree->Data = MinNode->Data;
			}
			// 외자식
			else {
				BSTNode* Temp = NULL;
				if (Tree->Left != NULL) {
					Temp = Tree->Left;
				}
				else {
					Temp = Tree->Right;
				}
				// 해당노드가 부모노드의 왼쪽인지 오른쪽인지 구별
				if (Parent->Left == Tree) {
					Parent->Left = Temp;
				}
				else
					Parent->Right = Temp;
			}
		}
	}
	return Removed;
}

// 트리 출력 함수
void BSTNode_InorderPrintTree(BSTNode* Node) {
	if (Node == NULL) {
		return;
	}

	// 왼쪽 하위 트리 출력
	BSTNode_InorderPrintTree(Node->Left);

	// 루트노드 출력
	printf("%d ", Node->Data);

	// 오른쪽 하위 트리 출력
	BSTNode_InorderPrintTree(Node->Right);
}
