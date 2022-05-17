#ifndef _BST_
#define _BST_

#include <stdio.h>
#include <stdlib.h>

// =======================bst=======================

typedef struct BinTreeNodeType
{
	int data;
	int visited;
	struct BinTreeNodeType	*pLeftChild;
	struct BinTreeNodeType	*pRightChild;
} BinTreeNode;

typedef struct BinTreeType
{
	struct BinTreeNodeType* pRootNode;
} BinTree;

BinTree *createBinTree(BinTreeNode rootNode);
BinTreeNode *createNode(BinTreeNode node);
BinTreeNode *getRootNodeBT(BinTree *pBinTree);
void pushNodeBT(BinTree *bt, BinTreeNode node);
int search(BinTree *tree, int data);
BinTreeNode	*getNodeBT(BinTree *bt, int data);

void	preorderTraversalBinTree(BinTreeNode *parentNode, int level);
void	inorderTraversalBinTree(BinTreeNode *parentNode, int level);
void	levelOrderTraversalBinTree(BinTreeNode *parentNode, int level);
#endif

#ifndef _COMMON_TREE_DEF_
#define _COMMON_TREE_DEF_

#define TRUE		1
#define FALSE		0
#define ERROR		-1

#endif