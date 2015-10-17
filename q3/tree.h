#ifndef TREE_H
#define TREE_H


typedef struct TreeNode{
	int value;
	struct TreeNode *left;
	struct TreeNode *right;
}Node;

void insert(Node ** tree, int val);
void print_preorder(Node * tree);
void print_inorder(Node * tree);
void print_postorder(Node * tree);
#endif