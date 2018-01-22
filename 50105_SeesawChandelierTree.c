#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
//#include "construct.h"
 
#define MAXN 16384
 
int T[MAXN];
typedef struct Node{
    int value;
    struct Node *left, *right;
}Node;

Node * LinkRemnants(Node *root, int seq[], int Lbound, int Rbound){
    root = (Node *)malloc( sizeof(Node) );
    root->value = seq[Rbound];
    root->right = NULL;
    if( Rbound-1 >= Lbound )
        root->left = LinkRemnants(root->left, seq, Lbound, Rbound-1);
    else
        root->left = NULL;

    return root;
}

Node * BalanceConstruct(Node *root, int seq[], int Lbound, int Rbound){
    long long weight = 0, torque = 0;
    for(int i = Lbound;i <= Rbound;i++){
        weight += seq[i];
        torque += seq[i] * (i-Lbound);
    }

    if( (Rbound-Lbound < 2) || (torque % weight) )
        return LinkRemnants(root, seq, Lbound, Rbound);

    int partition = Lbound + torque/weight;

    root = (Node *)malloc( sizeof(Node) );
    root->value = seq[ partition ];
    if( partition-1 >= Lbound )
        root->left = BalanceConstruct(root->left, seq, Lbound, partition-1);
    else
        root->left = NULL;
    if( partition+1 <= Rbound )
        root->right = BalanceConstruct(root->right, seq, partition+1, Rbound);
    else
        root->right = NULL;

    return root;
}
 
Node * ConstructTree(int T[], int N){
    Node *root = NULL;
    root = BalanceConstruct(root, T, 0, N-1);
    return root;
}
 
void PrintTree( Node *root ){
    if (root == NULL)
        return;
 
    printf("%d\n", root->value);
    PrintTree(root->left);
    PrintTree(root->right);
    return;
}
 
int main(){
    int N;
    scanf("%d", &N);
    for (int i=0; i<N; i++)
        scanf("%d", &T[i]);
 
    Node *tree = ConstructTree( T, N );
 
    PrintTree( tree );
    return 0;
}