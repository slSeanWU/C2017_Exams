#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
 
typedef struct Node{
    char name[16];
    int height;
    int weight;
    struct Node *left, *right;
} Node;
 
 
Node *insert_bs_tree(Node *root, char name[], int h, int w)
{
  Node *current;
  if (root == NULL) {
    current = (Node *)malloc(sizeof(Node));
    assert(current != NULL);
    strcpy(current->name, name);
    current->height = h, current->weight = w;
 
    current->left = NULL;
    current->right = NULL;
    return current;
  }
 
#ifdef HEIGHT
  if (h < root->height) 
    root->left = insert_bs_tree(root->left, name, h, w);
  else
    root->right = insert_bs_tree(root->right, name, h, w);
  return root;
#endif 
 
#ifdef WEIGHT
  if (w < root->weight) 
    root->left = insert_bs_tree(root->left, name, h, w);
  else
    root->right = insert_bs_tree(root->right, name, h, w);
  return root;
#endif 
 
}
 
Node *ConstructBSTree(int N, char name[][16], int height[], int weight[]){
    Node *root = NULL;
 
    for(int i = 0;i < N;i++)
        root = insert_bs_tree(root, name[i], height[i], weight[i]);
 
    return root;
}

// main program provided for testing
#define MAXN 1024
char name[MAXN][16];
int height[MAXN];
int weight[MAXN];
 
void PrintBSTree( Node *root ){
    if (root == NULL)
        return;
    printf("%s\n", root->name);
    PrintBSTree(root->left);
    PrintBSTree(root->right);
    return;
}
 
int main(){
    int N;
    scanf("%d", &N);
    for (int i=0; i<N; i++)
        scanf("%s %d %d", name[i], &height[i], &weight[i]);
 
    Node *tree = ConstructBSTree( N, name, height, weight );
 
    PrintBSTree( tree );
    return 0;
}