#include "ArrayStack.h"

/* 스택 생성 */
void AS_CreateStack(ArrayStack** Stack, int Capacity) {
	/* 스택을 자유 저장소에 생성 */
	(*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));

	/* 입력된 Capacity   만큼의 노드를 자유저장소에 생성 */
	(*Stack)->Nodes = (Node*)malloc(sizeof(Node) * Capacity);

	/* Capactiy 및 Top 초기화 */
	(*Stack)->Capacity = Capacity;
	(*Stack)->Top = 0;
}
/* 스택 제거 */
void AS_DestroyStack(ArrayStack* Stack) {
	/* 스택 내 노드들을 자유저장소에서 제거 */
	free(Stack->Nodes);
	/* 스택을 자유저장소에서 해제 */
	free(Stack);

}
/* 삽입 */
void AS_Push(ArrayStack* Stack, ElementType Data) {
	int Position = Stack->Top;

	Stack->Nodes[Position].Data = Data; // 자유저장소의 포인터변수들을 [배열화] 하여 각 위치의 값들을 조정
	Stack->Top++;
}
/* 제거 */
ElementType	AS_Pop(ArrayStack* Stack) {
	int Position = --(Stack->Top); // Top으로 위치조정
	return Stack->Nodes[Position].Data; // Top의 값을 줄임으로써 삭제연산을 한 것처럼 할 수 있음.

}
/* Top값 가져오기 */
ElementType	AS_Top(ArrayStack* Stack) {
	int Position = Stack->Top - 1; // 배열에서 n번째를 가리키고싶으면  n-1을 하고 가리킨다.
	return Stack->Nodes[Position].Data;
}
/* 사이즈 체크 */
int	AS_GetSize(ArrayStack* Stack) {
	return Stack->Top;
}
/* 비었니? */
int	As_IsEmpty(ArrayStack* Stack) {
	return (Stack->Top) == 0;
}
