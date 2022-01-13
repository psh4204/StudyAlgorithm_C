#include "DoubleyLinkedList.h"

int main(void) {
	int i = 0;
	int Count = 0;
	Node* List = NULL;
	Node* NewNode = NULL;
	Node* Current = NULL;

	/* 노드 5개 추가 */
	for (i = 0; i < 5; i++) {
		NewNode = DLL_CreateNode(i);
		DLL_AppendNode(&List, NewNode);
	}

	/* List  출력 */
	Count = DLL_GetNodeCount(List);
	for (i = 0; i < Count; i++) {
		Current = DLL_GetNodeAt(List, i);
		printf("List[%d] : %d\r\n", i, Current->Data);
	}

	/* 모든 노들르 메모리에서 제거 */
	printf(" \nDestroying List ...\n");

	Count = DLL_GetNodeCount(List);

	for (i = 0; i < Count; i++) {
		Current = DLL_GetNodeAt(List, 0);

		if (Current != NULL) {
			DLL_RemoveNode(&List, Current);
			DLL_DestroyNode(Current);
		}
	}
	return 0;
}
