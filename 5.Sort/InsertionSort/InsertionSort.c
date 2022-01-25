#include <stdio.h>
#include <string.h>

void InsertionSort(int DataSet[], int Length) {
	int i = 0;
	int j = 0;
	int value = 0;

	for (i = 1; i < Length; i++) {	// 처음 고르는 값 갯수는 2개
		if (DataSet[i - 1] <= DataSet[i]) {
			continue;
		}
		value = DataSet[i]; // 고르는 값 마지막 값

		for (j = 0; j < i; j++) {
			if (DataSet[j] > value) { // 고르는 값 마지막 값이 뒤에 값들보다 크면 움직인다.
				// memove(목적지 주소, 옮길데이터 주소, 옮길데이터 크기);
				memmove(&DataSet[j + 1], &DataSet[j], sizeof(DataSet[0]) * (i - j));
				DataSet[j] = value;
				break;
			}
		}
	}
}

int main(void){
	int DataSet[] = { 6,4,2,3,1,5 };
	int Length = sizeof(DataSet) / sizeof(DataSet[0]);
	int i = 0;
	InsertionSort(DataSet, Length);
	
	printf("삽입정렬 \n");

	for (i = 0; i < Length; i++) {
		printf("%d", DataSet[i]);
	}

	printf("\n");
	
	return 0;
}
