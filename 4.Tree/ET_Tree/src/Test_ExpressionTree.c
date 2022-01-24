#include "ExpressionTree.h"

int main(void) {

	ETNode* Root = NULL;

	char PostfixExpression[20] = "71*52-/";
	ET_BuildExpressionTree(PostfixExpression, &Root);

	/* 트리출력 */
	printf("Preorder ...\n");
	ET_PreorderPrintTree(Root);
	printf("\n\n");

	/* 트리출력 */
	printf("Inorder ...\n");
	ET_InorderPrintTree(Root);
	printf("\n\n");
	
	/* 트리출력 */
	printf("Postorder ...\n");
	ET_PostorderPrintTree(Root);
	printf("\n\n");

	printf("Evaulation Result : %f\n", ET_Evaluate(Root));

	/*트리 소멸시키기*/
	ET_DestroyTree(Root);

	return 0;
}
