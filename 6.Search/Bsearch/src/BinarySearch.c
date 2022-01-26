#include "BinarySearch.h"

Score* BinarySearch(Score ScoreList[], int Size, double Target) {
	int Left, Right, Mid;
	Left = 0;
	Right = Size - 1;

	// 1. 중간값 나누고, 목표값과 비교
	// 2. 목표값이 중간값보다 작으면 왼쪽에서, 크면 오른쪽에서 이진탐색
	// 3. 중간값이 목표값과 같아질때까지 반복
	while (Left <= Right) {
		Mid = (Left + Right) / 2;
		if (Target == ScoreList[Mid].score) {
			return &(ScoreList[Mid]);
		}
		else if (Target > ScoreList[Mid].score) {
			Left = Mid + 1;
		}
		else {
			Right = Mid - 1;
		}
	}
	return NULL;
}

int CompareScore(const void* _elem1, const void* _elem2) {
	Score* elem1 = (Score*)_elem1;
	Score* elem2 = (Score*)_elem2;

	if (elem1->score > elem2->score) {
		return 1;
	}
	else if (elem1->score < elem2->score) {
		return -1;
	}
	else {
		return 0;
	}

}

int main(void) {
	int Length = sizeof(DataSet) / sizeof(DataSet[0]);
	int i = 0;
	Score* found = NULL;

	// 점수를 오름차순으로 정렬
	qsort((void*)DataSet, Length, sizeof(Score), CompareScore);

	// 671.8점 받은 학생 찾기
	found = BinarySearch(DataSet, Length, 671.78);

	printf("found : %d\n", found->number, found->score);

	return 0;
}
