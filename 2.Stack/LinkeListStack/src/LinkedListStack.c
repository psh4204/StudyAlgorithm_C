#include "LinkedListStack.h"

/* 스택 생성 */
void LLS_CreateStack(LinkedListStack** Stack) {
	/* 스택을 자유저장소에 생성 */
	(*Stack) = (LinkedListStack*)malloc(sizeof(LinkedListStack));
	(*Stack)->List	= NULL;
	(*Stack)->Top	= NULL;
}
/* 스택 제거 */
void LLS_DestroyStack(LinkedListStack* Stack) {
	while (!LLS_IsEmpty(Stack)) {
		Node* Popped = LLS_Pop(Stack);
		LLS_DestoryNode(Popped);
	}
	/* 스택을 자유저장소에서 해제 */
	free(Stack);
}

/* 노드 생성 */
Node* LLS_CreateNode(char* Data){
	/* 자유저장소에 노드 할당 */
	Node* NewNode = (Node*)malloc(sizeof(Node));

	/* 입력받은 문자열의 크기만큼을 자유저장소에 할당 */
	NewNode->Data = (char*)malloc(strlen(Data) + 1); // NULL 까지 길이를 쟤야 함.

	/* 자유 저장소에 문자열 복사 */
	strcpy(NewNode->Data, Data); // 데이터를 저장한다.
	NewNode->NextNode = NULL; // 다음 노드에 대한 포인터를 초기화 한다.
	return NewNode; // 노드주소를 반환한다.
}
/* 노드 제거 */
void LLS_DestroyNode(Node* _Node){
	free(_Node->Data);
	free(_Node);
}

/* 삽입 연산 */
void LLS_Push(LinkedListStack* Stack, Node* NewNode){
	// NULL 내에 데이터 없으면 
	if (Stack->List == NULL) {
		Stack->List = NewNode;
	}
	else {
		// 최상위 노드를 찾아  NewNode를 연결
		Node* OldTop = Stack->List;
		while (OldTop->NextNode != NULL) {
			OldTop = OldTop->NextNode;
		}
		OldTop->NextNode = NewNode;
	}
	// 스택의 Top 필드에 새 노드 주소를 등록한다.
	Stack->Top = NewNode;
}
Node* LLS_Pop(LinkedListStack* Stack){
	// 현재 노드의 주소를 복사
	Node* TopNode = Stack->Top;

	if (Stack->List == Stack->Top) {
		Stack->List = NULL;
		Stack->Top = NULL;
	}
	else {
		// 새로운 최상위 노드를 스택의 Top필드에 등록
		Node* CurrentTop = Stack->List;
		while(CurrentTop != NULL && CurrentTop->NextNode != Stack->Top) {
			CurrentTop = CurrentTop->NextNode;
		}

		Stack->Top = CurrentTop;
		CurrentTop->NextNode = NULL;
	}
	// 삭제된 Top 리턴
	return TopNode;
}

Node* LLS_Top(LinkedListStack* Stack){
	return Stack->Top;

}
int LLS_GetSize(LinkedListStack* Stack){
	int count = 0;
	Node* Cursor = Stack->List;
	while (Cursor->NextNode != Stack->Top) {
		count++;
	}
	return count;
}
int LLS_IsEmpty(LinkedListStack* Stack){
	return (Stack->List == NULL);
}
