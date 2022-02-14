#include "../inc/RedBlackTree.h"

extern RBTNode * Nil; // 더미 끝 노드
void RBT_DestroyTree(RBTNode* Tree);

RBTNode* RBT_CreateNode(ElementType NewData);
void RBT_DestoryNode(RBTNode* Node);

RBTNode* RBT_SearchNode(RBTNode* Tree, ElementType Target){
    return 0;
}
RBTNode* RBT_SearchMinNode(RBTNode* Tree){
    return 0;
}

// 레드블랙트리_삽입
void RBT_InsertNode(RBTNode** Tree, RBTNode* NewNode){
    // 노드 삽입 (이진트리)
    RBT_InsertNodeHelper(Tree, NewNode); 

    // 노드 초기화 ( 빨간색, NIL, NIL )
    NewNode->Color = RED;
    NewNode->Left = Nil;
    NewNode->Right = Nil;

    // RBT 규칙 바로잡기
    RBT_RebuildAfterInsert(Tree, NewNode);
}
void RBT_InsertNodeHelper(RBTNode** Tree, RBTNode* NewNode){
    
}
RBTNode* RBT_RemoveNode(RBTNode** Root, ElementType Target){

}

// 레드블랙트리_Insert 후 규칙 바로잡기
// - 삽입 노드는 이미 빨간색이다.
// - 4번규칙( 빨강 자식은 전부 검은색 ) 을 중점으로 고쳐나간다.
//   - 4번 : 나만 아니면 돼~~ 
// - 실제 삽입 후, 삽입노드의 커서(X)만 이동하며 색을 바꾸거나, 회전을 한다.
void RBT_RebuildAfterInsert(RBTNode** Root, RBTNode* X){
    // 4번 규칙을 어기는 이상 계속 반복
    while(X != (*Root) && X->Parent->Color == RED){
        // (1) 부모노드가 할배노드의 왼쪽일 때,
        if(X->Parent == X->Parent->Parent->Left){
            // 삼촌노드 등장
            RBTNode * Uncle = X->Parent->Parent->Right;
            // - 삼촌노드가 빨간색일 때
            if(Uncle->Color == RED){
                X->Parent->Color    = BLACK;
                Uncle->Color        = BLACK;
                X->Parent->Color    = RED;
                // 할배 노드가 4번규칙에 어긋날 수 있기 때문에,
                // 삽입노드와 교체한다.
                X = X->Parent->Parent;
            }
            // - 삼촌노드가 검정색일 때
            else{
                // 나는(커서) 오른쪽
                if(X== X->Parent->Right){
                    X=X->Parent;
                    RBT_RotateLeft(Root, X);
                }
                // 나는 왼쪽으로 진행(부모노드가 현재 X노드)
                X->Parent->Color            = BLACK;
                X->Parent->Parent->Color    = RED;
                RBT_RotateRight(Root, X->Parent->Parent);
            }
        }
        else{
            // 부모가 오른쪽 자식인 경우
        }
    }
}

void RBT_RebuildAfterRemove(RBTNode** Root, RBTNode* X){

}

void RBT_PrintTree(RBTNode* Tree, int Depth, int BlackCount);

// 레드블랙트리_좌회전
void RBT_RotateLeft(RBTNode** Root, RBTNode* Parent){
    RBTNode * RightChild = Parent->Right;
    // 오른쪽 자식의 왼쪽 자식노드 -> 부모노드의 오른쪽 자식
    Parent->Right = RightChild->Left;
    if(RightChild->Left != Nil){
        RightChild->Left->Parent = Parent; // 그 노드의 부모까지 부모노드로 바꾼다.
    }
    // 부모노드의 부모까지 오른쪽 자식에게 넘겨준다.
    RightChild->Parent = Parent->Parent;
    if(Parent->Parent == NULL){  // 부모노드가 루트노드라면, 왼쪽 자식이 루트가 된다.
        (*Root) = RightChild;
    }
    else
    { 
        // 오른쪽 자식 노드를 부모노드에 위치시킨다.
        // 부모의 부모(할아버지)노드 기준 부모노드가 왼쪽이라면
        if(Parent == Parent->Parent->Left){
            Parent->Parent->Left = RightChild;
        }
        // 오른쪽이라면
        else{
            Parent->Parent->Right = RightChild;
        }
    }
    // 회전 마무리
    RightChild->Left = Parent;
    Parent->Parent = RightChild;
}

// 레드블랙트리_우회전
// - 부모노드의 '왼쪽 자식의 오른쪽 자식' 을 '부모노드의 오른쪽 자식노드' 로 바꿈.
void RBT_RotateRight(RBTNode** Root, RBTNode* Parent){
    RBTNode * LeftChild = Parent->Left;
    // 왼쪽 자식의 오른쪽 자식노드 -> 부모노드의 왼쪽자식
    Parent->Left = LeftChild->Right;
    if(LeftChild->Right != Nil){
        LeftChild->Right->Parent = Parent; // 그 노드의 부모까지 부모노드로 바꾼다.
    }
    // 부모노드의 부모까지 왼쪽 자식에게 넘겨준다.
    LeftChild->Parent = Parent->Parent;
    if(Parent->Parent == NULL){  // 부모노드가 루트노드라면, 왼쪽 자식이 루트가 된다.
        (*Root) = LeftChild;
    }
    else
    { 
        // 왼쪽 자식 노드를 부모노드에 위치시킨다.
        // 부모의 부모(할아버지)노드 기준 부모노드가 왼쪽이라면
        if(Parent == Parent->Parent->Left){
            Parent->Parent->Left = LeftChild;
        }
        // 오른쪽이라면
        else{
            Parent->Parent->Right = LeftChild;
        }
    }
    // 회전 마무리
    LeftChild->Right = Parent;
    Parent->Parent = LeftChild;
}
