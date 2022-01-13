#include "CircularDoublyLinkdeList.h"

int main(void) {
	int i = 0;
	int Count = 0;
	Node* List = NULL;
	Node* NewNode = NULL;
	Node* Current = NULL;

	/* 노드 5개 추가 */
	for (i = 0; i < 5; i++) {
		NewNode = CDLL_CreateNode(i);
		CDLL_AppendNode(&List, NewNode);
	}

	/* List  출력 */
	Count = CDLL_GetNodeCount(List);
	for (i = 0; i < Count*2; i++) {
		if (i == 0) {
			Current = List;
		}
		else {
			Current = Current->NextNode;
		}
		printf("List[%d] : %d\r\n", i, Current->Data);
	}

	/* 모든 노들르 메모리에서 제거 */
	printf(" \nDestroying List ...\n");

	Count = CDLL_GetNodeCount(List);

	for (i = 0; i < Count; i++) {
		Current = CDLL_GetNodeAt(List, 0);

		if (Current != NULL) {
			CDLL_RemoveNode(&List, Current);
			CDLL_DestroyNode(Current);
		}
	}
	return 0;
}
