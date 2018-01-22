#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
//#include "construct.h"
#define MAXN 16384

#ifndef MAXLENGTH
#define MAXLENGTH 5
#endif
 
int sequence[MAXN];
typedef struct node{
    int value;
    struct node *left, *right;
}Node;

int cmp(const void *a, const void *b){
	return *(int *)b - *(int *)a;
}

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

Node * PartitionConstruct(Node *root, int seq[], int Lbound, int Rbound){
	if( Rbound-Lbound+1 < MAXLENGTH )
		return LinkRemnants(root, seq, Lbound, Rbound);

	int size = Rbound-Lbound+1;
	int tmp[size+1];
	memcpy(tmp, seq+Lbound, sizeof(tmp));
	qsort(tmp, size, sizeof(int), cmp);

	int partition;
	for(partition = Lbound ; partition <= Rbound ; partition++)
		if(seq[ partition ] == tmp[ MAXLENGTH-1 ])
			break;

	root = (Node *)malloc( sizeof(Node) );
	root->value = seq[ partition ];
	if( partition-1 >= Lbound )
		root->left = PartitionConstruct(root->left, seq, Lbound, partition-1);
	else
		root->left = NULL;
	if( partition+1 <= Rbound )
		root->right = PartitionConstruct(root->right, seq, partition+1, Rbound);
	else
		root->right = NULL;

	return root;
}

Node * ConstructTree(int sequence[], int N){
	Node *root = NULL;
	root = PartitionConstruct(root, sequence, 0, N-1);
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
        scanf("%d", &sequence[i]);
    Node *tree = ConstructTree( sequence, N );
    PrintTree( tree );
    return 0;
}