#ifndef REDBLACKTREE_H
#define REBLACKTREE_H

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagRBTNode {
	struct tagRBTNode* Parent;
	struct tagRBTNode* Left;
	struct tagRBTNode* Right;

	enum { RED, BLACK } Color;

	ElementType Data;
} RBTNode;

void RBT_DestroyTree(RBTNode* Tree);

RBTNode* RBT_CreateNode(ElementType NewData);
void RBT_DestoryNode(RBTNode* Node);

RBTNode* RBT_SearchNode(RBTNode* Tree, ElementType Target);
RBTNode* RBT_SearchMinNode(RBTNode* Tree);
void RBT_InsertNode(RBTNode** Tree, RBTNode * NewNode);
void RBT_InsertNodeLerper(RBTNode** Tree, RBTNode * NewNode);
RBTNode* RBT_RemoveNode(RBTNode** Root, ElementType Target);
void RBT_RebuildAfterInsert(RBTNode** Tree, RBTNode* NewNode);
void RBT_RebuildAfterRemove(RBTNode** Root, RBTNode* X);

void RBT_PrintTree(RBTNode* Tree, int Depth, int BlackCount);
void RBT_RotateLeft(RBTNode** Root, RBTNode* Parent);
void RBT_RotateRight(RBTNode** Tree, RBTNode* Parent);

#endif
