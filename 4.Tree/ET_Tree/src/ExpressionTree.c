#include "ExpressionTree.h"

/* 노드 생성 */
ETNode* ET_CreateNode(ElementType NewData) {
	ETNode* NewNode = (ETNode*)malloc(sizeof(ETNode));
	NewNode->Left = NULL;
	NewNode->Right = NULL;
	NewNode->Data = NewData;

	return NewNode;
}
/* 노드 해제 */
void ET_DestroyNode(ETNode* Node) {
	free(Node);
}
/* Tree 제거 */
// 후위순회를 이용하면 어떤트리던 문제없이 삭제할 수 있다.
void ET_DestroyTree(ETNode* Root) {
	if (Root == NULL) return;

	/* 왼쪽 하위 트리 소멸 */
	ET_DestroyTree(Root->Left);
	/* 오른쪽 하위 트리 소멸 */
	ET_DestroyTree(Root->Right);
	/* 루트노드 소멸 */
	ET_DestroyNode(Root);
}

/* 전위순회 이진트리 출력 */
void ET_PreorderPrintTree(ETNode* Node) {
	if (Node == NULL) return;

	/* 루트노드 출력 */
	printf(" % c", Node->Data);
	/* 왼쪽 하위 트리 출력 */
	ET_PreorderPrintTree(Node->Left);
	/* 오른쪽 하위 트리 출력 */
	ET_PreorderPrintTree(Node->Right);
}
/* 중위순회 이진트리 출력 */
void ET_InorderPrintTree(ETNode* Node) {
	if (Node == NULL) return;

	/* 왼쪽 하위 트리 출력 */
	ET_InorderPrintTree(Node->Left);
	/* 루트노드 출력 */
	printf(" % c", Node->Data);
	/* 오른쪽 하위 트리 출력 */
	ET_InorderPrintTree(Node->Right);
}
/* 후위순회 이진트리 출력 */
void ET_PostorderPrintTree(ETNode* Node) {
	if (Node == NULL) return;

	/* 왼쪽 하위 트리 출력 */
	ET_PostorderPrintTree(Node->Left);
	/* 오른쪽 하위 트리 출력 */
	ET_PostorderPrintTree(Node->Right);
	/* 루트노드 출력 */
	printf(" % c", Node->Data);
}

/* 수식트리 구축 */
void ET_BuildExpressionTree(char* PostfixExpression, ETNode** Node) {
	int len = strlen(PostfixExpression);
	char Token = PostfixExpression[len - 1];
	PostfixExpression[len - 1] = '\0';

	switch (Token) {
		/* 연산자인 경우 */
	case '+' : case'-':case'*':case'/':
		(*Node) = ET_CreateNode(Token);
		ET_BuildExpressionTree(PostfixExpression, &(*Node)->Right);
		ET_BuildExpressionTree(PostfixExpression, &(*Node)->Left);
		break;

	/* 피연산자일 경우 */
	default:
		(*Node) = ET_CreateNode(Token);
		break;
	}
}

/* 수식트리 게산하기 */
// 코드를 보면 재귀함수로 트리를 그리는 느낌이다.
double ET_Evaluate(ETNode* Tree) {
	char Temp[2];

	double Left = 0;
	double Right = 0;
	double Result = 0;
	if (Tree == NULL)
		return 0;

	switch (Tree->Data) {
		/* 연사자인 경우 */
		case '+':case'-':case'*':case'/':
			Left = ET_Evaluate(Tree->Left);
			Right = ET_Evaluate(Tree->Right);

			if (Tree->Data == '+') Result = Left + Right;
			else if (Tree->Data == '-') Result = Left - Right;
			else if (Tree->Data == '*') Result = Left * Right;
			else if (Tree->Data == '/') Result = Left / Right;
		
			break;
		/* 피연산자인 경우 */
		default : 
			memset(Temp, 0, sizeof(Temp));
			Temp[0] = Tree->Data;
			Result = atof(Temp);
			break;
	}
	return Result;
}
