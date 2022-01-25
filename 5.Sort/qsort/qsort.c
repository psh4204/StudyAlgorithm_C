#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* 리턴값이 */
/* 0 보다 크면 elem1 < elem2 */
/* 0 이면 elem1 = elem2 */
/* 0 보다 작으면 elem1 > elem2 */
int CompareScore(const void* _elem1, const void* _elem2) {
	int* elem1 = (int*)_elem1;
	int* elem2 = (int*)_elem2;

	if (*elem1 > *elem2) {
		return 1;
	}
	else if (*elem1 < *elem2) {
		return -1;
	}
	else {
		return 0;
	}
}

int main(void) {
	int DataSet[] = { 6, 4, 2, 3, 1, 5 };
	int Length = sizeof(DataSet) / sizeof(DataSet[0]);
	int i = 0;
	// qsort(배열주소, 배열길이, 요소크기, 비교함수포인터)
	qsort((void*)DataSet, Length, sizeof(int), CompareScore);

	for (i = 0; i < Length; i++) {
		printf("%d ", DataSet[i]);
	}

	printf("\n");

	return 0;
}
