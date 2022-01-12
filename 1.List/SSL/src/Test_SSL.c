#include "LinkedList.h"

int main(void) {
	int	i = 0;
	int	Count = 0;
	Node* List = NULL; // 리스트 헤드가 들어갈 빈 깡통 (새 노드(주소)들이 들어갈 것임)
	Node* Current = NULL;
	Node* NewNode = NULL;

	/* Node 5개 추가 */
	for (i = 0; i < 5; i++) {
		// 리스트헤드에 새 노드들을 넣어서 연결
		NewNode = SSL_CreateNode(i);
		SSL_AppendNode(&List, NewNode);
	}

	NewNode = SSL_CreateNode(-1); // 데이터 -1이 들어있는 새 노드 생성
	SSL_InsertNewHead(&List, NewNode);

	NewNode = SSL_CreateNode(-2); // 데이터 -2이 들어있는 새 노드 생성
	SSL_InsertNewHead(&List, NewNode);

	/* 리스트 출력 */
	Count = SSL_GetNodeCount(List);
	for (i = 0; i < Count; i++) {
		Current = SSL_GetNodeAt(List, i);
		printf("List[%d] : %d\n", i, Current->Data);
	}

	/* 모든 노드를 메모리에서 제거 */
	for (i = 0; i < Count; i++) {
		// 첫번째 값들을 계속 삭제한다.
		Current = SSL_GetNodeAt(List, 0);
		// 현재 값이 존재한다면 삭제함수를 부른다.
		if (Current != NULL) {
			// 노드 삭제처리
			SSL_RemoveNode(&List, Current);
			// 메모리에서 노드 소멸
			SSL_DestroyNode(Current);
		}
	}

	return 0;
}
