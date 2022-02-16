#include "Heap.h"

Heap*   HEAP_Create(int InitSize){
    Heap* NewHeap = (Heap*) malloc(sizeof(Heap));
    NewHeap->Capacity = InitSize;
    NewHeap->UsedSize = 0;
    NewHeap->Nodes = (HeapNode*) malloc(sizeof(HeapNode)* NewHeap->Capacity);

    printf("size : %d\n", sizeof(HeapNode));
    return NewHeap;
}

void    HEAP_Destory(Heap * H){
    free(H->Nodes);
    free(H);
}

// 힙 삽입
// 1. 가장 깊은 곳의 가장 우측에 삽입
// 2. 삽입노드의 부모와 비교하며, 더 크다면 서로 바꿈
// 3. 부모노드가 더 작을때 까지 2번 반복.
void    HEAP_Insert(Heap* H, ElementType NewData){
    int CurrentPosition = H->UsedSize;
    int ParentPosition = HEAP_GetParent(CurrentPosition);

    // UsedSize가 Capacity에 도달하면 Capcit를 
    if(H->UsedSize == H->Capacity){
        H->Capacity *= 2;
        H->Nodes = (HeapNode*)realloc(H->Nodes,sizeof(HeapNode)*H->Capacity); // 해당 메모리 크기를 Capacity 크기로 키움
    }

    H->Nodes[CurrentPosition].Data = NewData;

    // 후속처리
    while(CurrentPosition > 0
    && H->Nodes[CurrentPosition].Data < H->Nodes[ParentPosition].Data){
        HEAP_SwapNodes(H, CurrentPosition, ParentPosition);

        CurrentPosition = ParentPosition;
        ParentPosition = HEAP_GetParent(CurrentPosition);
    }
    H->UsedSize++;
}


// 힙 (최소값) 삭제
// 1. 루트노드 삭제 및 가장 깊은 곳 가장 우측 노드를 루트자리에 삽입
// 2. 자식노드랑 비교해서 자식이 더 작으면 가장 작은자식과 자리변경
// 3. 완전히 잎노드로 간다던지, 자식노드가 더클때까지 2번 반복.
void    HEAP_DeleteMin(Heap* H, HeapNode* Root){
    int ParentPosition = 0;
    int LeftPosition = 0;
    int RightPosition = 0;

    memcpy(Root, &H->Nodes[0], sizeof(HeapNode));   // Root의 최소값을 저장한다.
    memset(&H->Nodes[0], 0, sizeof(HeapNode));     // Root 노드를 비운다.

    LeftPosition = HEAP_GetLeftChild(0);
    RightPosition = LeftPosition+1;

    // Heap순서 속성을 만족시킬 때 까지 노드교환을 반복한다.
    while(1){
        int SelectedChild = 0;

        if(LeftPosition >= H->UsedSize) break;

        if(RightPosition >= H->UsedSize){
            SelectedChild = LeftPosition;
        }
        else{
            if(H->Nodes[LeftPosition].Data > H->Nodes[RightPosition].Data) SelectedChild = RightPosition;
            else SelectedChild = LeftPosition;
        }

        if(H->Nodes[SelectedChild].Data < H->Nodes[ParentPosition].Data){
            HEAP_SwapNodes(H, ParentPosition, SelectedChild);
            ParentPosition = SelectedChild;
        }
        else 
            break;

        LeftPosition = HEAP_GetLeftChild(ParentPosition);
        RightPosition = LeftPosition+1;
    }
    
    if(H->UsedSize < (H->Capacity/2)){
        H->Capacity /= 2;
        H->Nodes =
            (HeapNode*) realloc(H->Nodes, sizeof(HeapNode) * H->Capacity);
    }
}

int     HEAP_GetParent(int Index){
    return (int)((Index -1)/2);
}
int     HEAP_GetLeftChild(int Index){
    return (2*Index)+1;
}
void    HEAP_SwapNodes(Heap* H, int Index1, int Index2){
    int CopySize = sizeof(HeapNode);
    HeapNode * Temp = (HeapNode*)malloc(CopySize);

    memcpy(Temp, &H->Nodes[Index1], CopySize);              // Temp에 노드1 저장
    memcpy(&H->Nodes[Index1], &H->Nodes[Index2], CopySize); // 노드1에 노드2 저장
    memcpy(&H->Nodes[Index2], Temp, CopySize);              // 노드2에 Temp(노드1) 저장

    free(Temp);
}
void    HEAP_PrintNodes(Heap* H){
    int i = 0;
    for(i = 0; i<H->UsedSize; i++){
        printf("%d", H->Nodes[i].Data);
    }
    printf("\n");
}
