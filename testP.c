#include<stdio.h>
#include<stdlib.h>
typedef char ElemType;

typedef struct BTNode{
    ElemType data;
    struct BTNode* Lchild;
    struct BTNode* Rchild;
}BTNode;

int NodeIndex;
void createBiTree(BTNode *T,char s[]);
void createNode(BTNode *T,char s[]);


int main(){
    
}


void createBiTree(BTNode *T,char s[]){
    NodeIndex=0;
    if(s[NodeIndex]=='#')T=NULL;
    else{
        T=(BTNode*)malloc(sizeof(BTNode));
        T->data=s[NodeIndex];
        NodeIndex++;
        createBiTree(T->Lchild,s);
        createBiTree(T->Rchild,s);
    }
}