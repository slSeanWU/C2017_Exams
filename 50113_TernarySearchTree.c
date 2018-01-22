#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
//#include "construct.h"
#define MAXN 32768

int sequence[MAXN];
typedef struct node{
    int small,large;
    struct node *left,*mid,*right;
}Node;

Node * myConstruct(Node *root, int value){
    if( root == NULL ){
        Node *newNode = (Node *)malloc(sizeof(Node));
        newNode->large = value;
        newNode->small = -1;
        newNode->left = newNode->mid = newNode->right = NULL;

        return newNode;
    }

    if( root->small == -1 ){
        if(value < root->large)
            root->small = value;
        else{
            root->small = root->large;
            root->large = value;
        }
    }

    else{
        if(value < root->small)
            root->left = myConstruct(root->left, value);
        else if(value > root->large)
            root->right = myConstruct(root->right, value);
        else
            root->mid = myConstruct(root->mid, value);
    }

    return root;
}

Node * ConstructTree(int sequence[],int N){
    Node *root = (Node *)malloc(sizeof(Node));
    root->large = sequence[0];
    root->small = -1;
    root->left = root->mid = root->right = NULL;

    for(int i = 1;i < N;i++)
        root = myConstruct(root, sequence[i]);

    return root;
}

void PrintTree( Node *root ){
    if (root == NULL)
        return;
    printf("%d %d\n", root->small, root->large);
    PrintTree(root->left);
    PrintTree(root->mid);
    PrintTree(root->right);
    return;
}

int main(){
    int N;
    scanf("%d", &N);
    for (int i=0; i<N; i++)
        scanf("%d", &sequence[i]);
    Node *tree = ConstructTree( sequence, N );
    PrintTree( tree );
    return 0;
}