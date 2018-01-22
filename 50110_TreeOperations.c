#include <stddef.h>
#include <stdlib.h>
//#include "operations.h"

typedef struct Node{
    int n;
    struct Node *left, *right;
}Node;
 
Node *myFlip(Node *root){
    if(root == NULL)
        return NULL;
 
    Node *new = (Node *)malloc( sizeof(Node) );
    new->n = root->n;
    new->left = myFlip(root->right);
    new->right = myFlip(root->left);
 
    return new;
}
Node *FlipTree(Node *root){
    Node *newTree = myFlip(root);
    return newTree;
}
 
int isIdentical(Node *tree1, Node *tree2){
    if( tree1 == NULL && tree2 == NULL )
        return 1;
    if( tree1 == NULL && tree2 != NULL )
        return 0;
    if( tree1 != NULL && tree2 == NULL )
        return 0;
    if( tree1->n != tree2->n )
        return 0;
 
    int LI = isIdentical(tree1->left, tree2->left);
    int RI = isIdentical(tree1->right, tree2->right);
 
    return (LI && RI);
}
 
int sum, cnt;
void myDepth(int lev, Node *root){
    if(root->left == NULL && root->right == NULL){
        sum += lev, cnt++;
        return;
    }
 
    if(root->left != NULL)
        myDepth(lev+1, root->left);
    if(root->right != NULL)
        myDepth(lev+1, root->right);
 
    return;
}
void depthAvg(Node *root){
    sum = 0, cnt = 0;
    myDepth(0, root);
    printf("%d/%d\n", sum, cnt);
 
    return;
}

// main functions provided for testing

/* 1) FlipTree

#include <stdio.h>
 
void printTree(Node *root) {
  if (root == NULL) {
    printf("NULL\n");
    return;
  }
  printf("%d\n", root->n);
  if (root->left == NULL && root->right == NULL) return;
  printTree(root->left);
  printTree(root->right);
}
 
int main() {
  Node node[9];
 
  for(int i = 0; i < 9; i++){
    node[i].n = i;
    node[i].left = node[i].right = NULL;
  }
 
  node[0].left = &node[1];
  node[0].right = &node[2];
  node[1].left = &node[3];
  node[1].right = &node[4];
  node[2].left = &node[5];
  node[2].right = &node[6];
  node[4].left = &node[7];
  node[6].right = &node[8];
 
  Node *tree = FlipTree(&node[0]);
  printTree(&node[0]);
  printTree(tree);
 
  return 0;
}
*/

/* 2) isIdentical

#include <stdio.h>
 
int main() {
  Node tree1[9];
  Node tree2[9];
 
  for(int i = 0; i < 9; i++){
    tree1[i].n = tree2[i].n = i;
    tree1[i].left = tree1[i].right = NULL;
    tree2[i].left = tree2[i].right = NULL;
  }
 
  tree1[0].left = &tree1[1];
  tree1[0].right = &tree1[2];
  tree1[1].left = &tree1[3];
  tree1[1].right = &tree1[4];
  tree1[2].left = &tree1[5];
  tree1[2].right = &tree1[6];
  tree1[4].left = &tree1[7];
  tree1[6].right = &tree1[8];
 
  tree2[0].left = &tree2[1];
  tree2[0].right = &tree2[2];
  tree2[1].left = &tree2[3];
  tree2[1].right = &tree2[4];
  tree2[2].left = &tree2[5];
  tree2[2].right = &tree2[8];
  tree2[4].left = &tree2[6];
  tree2[6].right = &tree2[7];
 
  printf("%d\n", isIdentical(&tree1[0], &tree2[0]));
  printf("%d\n", isIdentical(&tree1[0], &tree1[0]));
  return 0;
}
*/

/* 3) depthAvg

#include <stdio.h>
 
int main() {
  Node tree1[9];
 
  for(int i = 0; i < 9; i++){
    tree1[i].n = i;
    tree1[i].left = tree1[i].right = NULL;
  }
 
  tree1[0].left = &tree1[1];
  tree1[0].right = &tree1[2];
  tree1[1].left = &tree1[3];
  tree1[1].right = &tree1[4];
  tree1[2].left = &tree1[5];
  tree1[2].right = &tree1[8];
  tree1[4].left = &tree1[6];
  tree1[6].right = &tree1[7];
 
  depthAvg(&tree1[0]);
 
  return 0;
}
*/