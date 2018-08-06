#include<stdio.h>
#include<stdlib.h>
typedef char ElemType;

typedef struct BTNode{
    ElemType data;
    struct BTNode* Lchild;
    struct BTNode* Rchild;
}BTNode;


int NodeIndex;
void createBiTree(BTNode **T,char s[]);
void createNode(BTNode **T,char s[]);


int main(){
    BTNode *Bitree;
    char s[]={"ab##c##"};
    createBiTree(&Bitree,s);
    printf("%c,%c\n",Bitree->data,Bitree->Lchild->data);
}


void createBiTree(BTNode **T,char s[]){
    NodeIndex=0;
    createNode(&*T,s);
}

void createNode(BTNode **T,char s[]){
    if(s[NodeIndex]=='#')T=NULL;
    else{
        (*T)=(BTNode*)malloc(sizeof(BTNode));
        (*T)->data=s[NodeIndex];
        NodeIndex++;
        createNode(&(*T)->Lchild,s);
        createNode(&(*T)->Rchild,s);
    }
}