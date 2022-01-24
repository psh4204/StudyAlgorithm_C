#include "DisjointSet.h"

int main(void) {
	int a = 1, b = 1, c = 3, d = 4;
	DisjointSet* Set1 = Ds_MakeSEt(&a);
	DisjointSet* Set2 = Ds_MakeSEt(&b);
	DisjointSet* Set3 = Ds_MakeSEt(&c);
	DisjointSet* Set4 = Ds_MakeSEt(&d);

	printf("Set1 == Set2 : %d \n", DS_FindSEt(Set1) == DS_FindSEt(Set2));

	DS_UnionSet(Set1, Set3);
	printf("Set1 == Set3 : %d \n", DS_FindSEt(Set1) == DS_FindSEt(Set3));

	DS_UnionSet(Set3, Set4);
	printf("Set3 == Set4 : %d \n", DS_FindSEt(Set3) == DS_FindSEt(Set4));
	return 0;
}
