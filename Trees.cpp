// Trees.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

#include "Stack.h"

using namespace std;

struct BinTreeNode {
	int data;
	struct BinTreeNode *left;
	struct BinTreeNode *right;
};

//In-order traversal of a given binary tree using recursion
void bintree_inorder_traversal_using_recursion(struct BinTreeNode *root) {
	if (root == NULL)
		return;

	bintree_inorder_traversal_using_recursion(root->left);
	cout << root->data << " ";
	bintree_inorder_traversal_using_recursion(root->right);
}

//Pre-order traversal of a given binary tree using recursion

void bintree_preorder_traversal_using_recursion(struct BinTreeNode *root) {
	if (root == NULL)
		return;

	cout << root->data << " ";
	bintree_preorder_traversal_using_recursion(root->left);
	bintree_preorder_traversal_using_recursion(root->right);
}

//Post-order traversal of a given binary tree using recursion
void bintree_postorder_traversal_using_recursion(struct BinTreeNode *root) {
	if (root == NULL)
		return;

	bintree_postorder_traversal_using_recursion(root->left);
	bintree_postorder_traversal_using_recursion(root->right);
	cout << root->data << " ";
}

//Level-order traversal

//Level-order traversal printing each level in a line

//In-order traversal of a given binary tree without recursion and using stack
void bintree_inorder_traversal_without_recursion(struct BinTreeNode *root) {
	
	Stack<struct BinTreeNode, int> s;
	bool done = false;
	struct BinTreeNode *cur = root;

	while (!done) {
		if (cur != NULL) {
			s.push(&cur);
			cur = cur->left;
		}
		else {
			struct BinTreeNode *poppedNode = NULL;
			if (!s.isEmpty()) {
				s.pop(&poppedNode);
				cout << poppedNode->data << " ";
				if (poppedNode->right != NULL)
					cur = poppedNode->right;
			}
			else
				done = true;
		}
	}
}

void bintree_inorder_traversal_without_recursion_without_stack(struct Node *root) {
	if(root == NULL)
		return;
		
	struct Node *cur=root, *pre=NULL;
	
	while(cur != NULL) {
		if(cur->left == NULL) {
			cout << cur->data << " ";
			cur = cur->right;
		}
		else {
			pre = cur->left;
			while(pre->right != NULL && pre->right != cur)
				pre = pre->right;
			
			if(pre->right == NULL){
				pre->right = cur;
				cur = cur->left;
			}
			else {
				cout << cur->data << " ";
				pre->right = NULL;
				cur = cur->right;
			}
		}
	}
}

//Mirror a Binary Tree

//Left View of a Binary Tree

//Right View of a Binary Tree


int main()
{
	struct BinTreeNode *n1 = (struct BinTreeNode *)malloc(sizeof(struct BinTreeNode));
	n1->left = NULL;
	n1->right = NULL;
	struct BinTreeNode *n2 = (struct BinTreeNode *)malloc(sizeof(struct BinTreeNode));
	n2->left = NULL;
	n2->right = NULL;
	struct BinTreeNode *n3 = (struct BinTreeNode *)malloc(sizeof(struct BinTreeNode));
	n3->left = NULL;
	n3->right = NULL;
	struct BinTreeNode *n4 = (struct BinTreeNode *)malloc(sizeof(struct BinTreeNode));
	n4->left = NULL;
	n4->right = NULL;
	struct BinTreeNode *n5 = (struct BinTreeNode *)malloc(sizeof(struct BinTreeNode));
	n5->left = NULL;
	n5->right = NULL;
	struct BinTreeNode *n6 = (struct BinTreeNode *)malloc(sizeof(struct BinTreeNode));
	n6->left = NULL;
	n6->right = NULL;
	struct BinTreeNode *n7 = (struct BinTreeNode *)malloc(sizeof(struct BinTreeNode));
	n7->left = NULL;
	n7->right = NULL;
	struct BinTreeNode *n8 = (struct BinTreeNode *)malloc(sizeof(struct BinTreeNode));
	n8->left = NULL;
	n8->right = NULL;
	struct BinTreeNode *n9 = (struct BinTreeNode *)malloc(sizeof(struct BinTreeNode));
	n9->left = NULL;
	n9->right = NULL;

	n1->data = 1;
	n2->data = 2;
	n3->data = 3;
	n4->data = 4;
	n5->data = 5;
	n6->data = 6;
	n7->data = 7;
	n8->data = 8;
	n9->data = 9;

	n1->left = n2;
	n1->right = n3;
	n2->left = n4;
	n2->right = n5;
	n5->left = n6;
	n3->left = n7;
	n7->left = n9;
	n7->right = n8;

	cout << "Inorder Traversal using Recursion" << endl;
	bintree_inorder_traversal_using_recursion(n1);
	cout << endl;

	cout << "Preorder traversal using recursion" << endl;
	bintree_preorder_traversal_using_recursion(n1);
	cout << endl;

	cout << "Postorder traversal using recursion" << endl;
	bintree_postorder_traversal_using_recursion(n1);
	cout << endl;

	cout << "Inorder traversal without recursion" << endl;
	bintree_inorder_traversal_without_recursion(n1);
	cout << endl;

	getchar();


	free(n1);
	free(n2);
	free(n3);
	free(n4);
	free(n5);
	free(n6);
	free(n7);
	free(n8);
	free(n9);

    return 0;
}

