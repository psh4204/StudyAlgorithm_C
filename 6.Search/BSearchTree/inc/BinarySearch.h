#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagBSTNode
{
	struct tagBSTNode* Left;
	struct tagBSTNode* Right;

	ElementType Data;
} BSTNode;

BSTNode* BST_CreateNode(ElementType NewData);
void BST_DestroyNode(BSTNode* Node);
void BST_DetroyTree(BSTNode* Tree);

BSTNode* BSTNode_SearchNode(BSTNode* Tree, ElementType Target);
BSTNode* BSTNode_SearchMinNode(BSTNode* Tree);
void BSTNode_InsertNode(BSTNode** Tree, BSTNode* Child);
BSTNode* BSTNode_RemoveNode(BSTNode* Tree, BSTNode* Parent, ElementType Target);
void BSTNode_InorderPrintTree(BSTNode* Node);

#endif
