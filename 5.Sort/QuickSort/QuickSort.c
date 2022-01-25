#include <stdio.h>

void Swap(int* A, int* B) {
	int Temp = *A;
	*A = *B;
	*B = Temp;
}

/* 중심점 중심으로 값들을 나누고 중심점을 배정하는 함수 */
int Partition(int DataSet[], int Left, int Right) { // (배열, 왼쪽커서 숫자, 오른쪽커서 숫자)
	int First = Left;
	int Pivot = DataSet[First];  // 중심점 값

	++Left;

	// 왼쪽과 오른쪽 커서가 닿거나 교차하게 될때 까지 반복
	while (Left <= Right) {
		// 왼쪽값이 중심값 보다 작을경우 + 왼쪽값이 왼쪽에 있을경우
		while (DataSet[Left] <= Pivot && Left < Right) {
			// 왼쪽 커서가 움직인다.(중심으로)
			++Left;
		}
		// 오른쪽값이 중심값 보다 클경우 + 오른쪽값이 오른쪽에 있을경우
		while (DataSet[Right] > Pivot && Left <= Right) {
			// 오른쪽 커서가 움직인다.(중심으로)
			--Right;
		}
		// 왼쪽값 과 오른쪽 값을 바꾼다.
		if (Left < Right) {
			Swap(&DataSet[Left], &DataSet[Right]);
		}
		else {
			break;
		}
		Swap(&DataSet[First], &DataSet[Right]);
	}
	// 중심값 중심으로 이동
	Swap(&DataSet[First], &DataSet[Right]);
	
	return Right;
}

// QuickSort 예제
void QuickSort(int DataSet[], int Left, int Right) {
	if (Left < Right) {
		// 중심 나누고 중심값 만들고 중심값+1 위치 리턴
		int Index = Partition(DataSet, Left, Right); // 오른쪽 위치 값( 중심점 + 1 위치 )
		
		// 왼쪽 부터 qsort
		QuickSort(DataSet, Left, Index - 1);
		// 다음 오른쪽 qsort
		QuickSort(DataSet, Index + 1, Right);
	}
}

int main(void){
	int DataSet[] = { 6,4,2,3,1,5 };
	int Length = sizeof(DataSet) / sizeof(DataSet[0]);
	int i = 0;

	QuickSort(DataSet, 0, Length - 1); //Quicksort(배열, 왼쪽, 오른쪽)
	
	for (i = 0; i < Length; i++) {
		printf("%d ", DataSet[i]);
	}
	printf("\n");

	return 0;
}
