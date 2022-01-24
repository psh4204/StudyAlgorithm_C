#include "DisjointSet.h"

// 합집합
void DS_UnionSet(DisjointSet* set1, DisjointSet* set2) {
	set2 = DS_FindSEt(set2);
	set2->Parent = set1;
}
// 집합 탐색
// - 부모노드가  NULL이면 그친구가 ROOT
DisjointSet* DS_FindSEt(DisjointSet* Set) {
	while (Set->Parent != NULL) {
		Set = Set->Parent;
	}
	return Set;
}
DisjointSet* Ds_MakeSEt(void* NewData) {
	DisjointSet* NewNode = (DisjointSet*)malloc(sizeof(DisjointSet));
	NewNode->Data = NewData;
	NewNode->Parent = NULL;

	return NewNode;
}
void DS_DestorySet(DisjointSet* Set) {
	free(Set);
}
