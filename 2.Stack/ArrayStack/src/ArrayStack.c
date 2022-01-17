#include "ArrayStack.h"

int main(void) {
	int i = 0;
	ArrayStack* Stack = NULL;

	AS_CreateStack(&Stack, 10);

	AS_Push(Stack, 3);
	AS_Push(Stack, 6);
	AS_Push(Stack, 7);
	AS_Push(Stack, 4);
	
	printf("Capacity : %d, Size : %d, Top : %d\r\n",
		Stack->Capacity, AS_GetSize(Stack), AS_Top(Stack));

	for (i = 0; i < 4; i++) {
		if (As_IsEmpty(Stack)) {
			break;
		}

		printf("Popped : %d", AS_Pop(Stack));

		if (!As_IsEmpty(Stack)) {
			printf("  Current Top : %d \n", AS_Top(Stack));
		}
		else {
			printf(" Stack Is Empty \n");
		}
	}
	return 0;
}
