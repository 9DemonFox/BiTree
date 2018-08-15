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
int CountNodes(BTNode *T);
void count(BTNode *T);

int main(){
    BTNode *Bitree;
    char s[]={"ab##c##"};
    createBiTree(&Bitree,s);
    PreOrderTraverse(Bitree);
    int totalNodes=CountNodes(Bitree);
    printf("%d",totalNodes);
    printf("\n");
    return 0;
}


void createBiTree(BTNode **T,char s[]){
    NodeIndex=0;
    createNode(&*T,s);
}

void createNode(BTNode **T,char s[]){
    if(s[NodeIndex]=='#'){
        T=NULL;
        NodeIndex++;
    }
    else{
        (*T)=(BTNode*)malloc(sizeof(BTNode));
        (*T)->data=s[NodeIndex];
        NodeIndex++;
        createNode(&(*T)->Lchild,s);
        createNode(&(*T)->Rchild,s);
    }
}

void visit(BTNode *T){
    printf("%c",T->data);
    return;
}

void PreOrderTraverse(BTNode *T){
    if(T==NULL)return;
    visit(T);
    PreOrderTraverse(T->Lchild);
    PreOrderTraverse(T->Rchild);
}


int totalNodes;
void count(BTNode *T)
{
    if(T==NULL)return ;
    totalNodes++;
    count(T->Lchild);
    count(T->Rchild);
}

int CountNodes(BTNode *T){
     totalNodes=0;
    count(T);
    return totalNodes;
}
