#include "bintree.h"

void	preorderTraversalBinTree(BinTreeNode *parentNode, int level)
{
	printf("level : %d\ndata : %c\n", level, parentNode->data);
	if (parentNode->pLeftChild)
		preorderTraversalBinTree(parentNode->pLeftChild, level + 1);
	if (parentNode->pRightChild)
		preorderTraversalBinTree(parentNode->pRightChild, level + 1);
}

void	inorderTraversalBinTree(BinTreeNode *parentNode, int level)
{
	if (parentNode->pLeftChild)
		inorderTraversalBinTree(parentNode->pLeftChild, level + 1);
	printf("level : %d\ndata: %c\n", level, parentNode->data);
	if (parentNode->pRightChild)
		inorderTraversalBinTree(parentNode->pRightChild, level + 1);
}

void	levelOrderTraversalBinTree(BinTreeNode *parentNode, int level)
{
	if (parentNode->pLeftChild)
		levelOrderTraversalBinTree(parentNode->pLeftChild, level + 1);
	if (parentNode->pRightChild)
		levelOrderTraversalBinTree(parentNode->pRightChild, level + 1);
	printf("level : %d\ndata: %c\n", level, parentNode->data);
}