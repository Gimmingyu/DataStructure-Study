#include "./bst.h"

BinTree *createBinTree(BinTreeNode rootNode)
{
	BinTree *newTree = calloc(1, sizeof(BinTree));
	BinTreeNode *root = createNode(rootNode);

	newTree->pRootNode = root;
	return (newTree);
}

BinTreeNode *createNode(BinTreeNode node)
{
	BinTreeNode *newNode = calloc(1, sizeof(BinTreeNode));

	newNode->data = node.data;
	newNode->visited = 0;
	return (newNode);
}

BinTreeNode *getRootNodeBT(BinTree *pBinTree)
{
	if (!pBinTree)
		return (NULL);
	printf("root node data = %c\n", pBinTree->pRootNode->data);
	return (pBinTree->pRootNode);
}

void pushNodeBT(BinTree *bt, BinTreeNode node)
{
	BinTreeNode *newNode;
	BinTreeNode *parent;

	if (!bt || search(bt, node.data))
		return;
	newNode = createNode(node);
	parent = bt->pRootNode;
	while (parent)
	{
		if (parent->data > newNode->data)
		{
			if (!parent->pLeftChild)
			{
				parent->pLeftChild = newNode;
				return;
			}
			parent = parent->pLeftChild;
		}
		else
		{
			if (!parent->pRightChild)
			{
				parent->pRightChild = newNode;
				return ;
			}
			parent = parent->pRightChild;
		}
	}
	if (!parent)
		bt->pRootNode = newNode;
}

void	popNodeBT(BinTree *bt, int data)
{
	BinTreeNode	*delNode;
	BinTreeNode	*parentNode;
	BinTreeNode	*replaceNode;
	BinTreeNode	*previousNode;

	if (!bt || !bt->pRootNode || search(bt, data))
		return; 
	delNode = getNodeBT(bt, data);
	parentNode = getParentNodeBT(bt, data);
	if (delNode->pLeftChild && delNode->pRightChild)
	{
		previousNode = delNode;
		replaceNode = delNode->pLeftChild;
		while (replaceNode->pRightChild)
		{
			previousNode = replaceNode;
			replaceNode = replaceNode->pRightChild;
		}
		if (previousNode->pLeftChild = replaceNode)
			previousNode->pLeftChild = replaceNode->pLeftChild;
		else
			previousNode->pRightChild = replaceNode->pLeftChild;
		delNode->data = replaceNode->data;
		delNode = replaceNode;
	}
	else if (!delNode->pLeftChild && !delNode->pRightChild)
	{
		if (parentNode->pLeftChild == delNode)
			parentNode->pLeftChild = NULL;
		else
			parentNode->pRightChild = NULL;
	}
	else
	{
		if (delNode->pLeftChild)
			replaceNode = delNode->pLeftChild;
		else
			replaceNode = delNode->pRightChild;

		if (parentNode->pLeftChild == delNode)
			parentNode->pLeftChild = replaceNode;
		else
			parentNode->pRightChild = replaceNode;
	}
	free(delNode);
}

BinTreeNode	*getNodeBT(BinTree *bt, int data)
{
	BinTreeNode	*tofind;

	tofind = bt->pRootNode;
	while (tofind)
	{
		if (tofind->data == data)
			return (tofind);
		else if (tofind->data > data)
			tofind = tofind->pLeftChild;
		else
			tofind = tofind->pRightChild;
	}
}

BinTreeNode	*getParentNodeBT(BinTree *bt, int data)
{
	BinTreeNode	*tofind;

	tofind = bt->pRootNode;
	if (tofind->pLeftChild->data == data || tofind->pRightChild->data == data)
		return (tofind);
	while (tofind)
	{
		if (tofind->pLeftChild->data == data || tofind->pRightChild->data == data)
			return (tofind) ;
		else if (tofind->data > data)
			tofind = tofind->pLeftChild;
		else
			tofind = tofind->pRightChild;
	}
}

int search(BinTree *tree, int data)
{
	BinTreeNode *result;

	if (!tree || !tree->pRootNode)
		return (ERROR);
	result = tree->pRootNode;
	while (result)
	{
		// 목표 키 값 찾은 경우
		if (result->data == data)
			return (TRUE);
		// 현재 키 값이 더 큰 경우 --> 작은 쪽으로 가야한다.
		else if (data < result->data)
			result = result->pLeftChild;
		// 현재 키 값이 더 작은 경우 --> 더 큰쪽으로 가야한다.
		else
			result = result->pRightChild;
	}
	return (FALSE);
}

void preorderTraversalBinTree(BinTreeNode *parentNode, int level)
{
	printf("level : %d\ndata : %d\n", level, parentNode->data);
	if (parentNode->pLeftChild)
		preorderTraversalBinTree(parentNode->pLeftChild, level + 1);
	if (parentNode->pRightChild)
		preorderTraversalBinTree(parentNode->pRightChild, level + 1);
}

void inorderTraversalBinTree(BinTreeNode *parentNode, int level)
{
	if (parentNode->pLeftChild)
		inorderTraversalBinTree(parentNode->pLeftChild, level + 1);
	printf("level : %d\ndata: %d\n", level, parentNode->data);
	if (parentNode->pRightChild)
		inorderTraversalBinTree(parentNode->pRightChild, level + 1);
}

void levelOrderTraversalBinTree(BinTreeNode *parentNode, int level)
{
	if (parentNode->pLeftChild)
		levelOrderTraversalBinTree(parentNode->pLeftChild, level + 1);
	if (parentNode->pRightChild)
		levelOrderTraversalBinTree(parentNode->pRightChild, level + 1);
	printf("level : %d\ndata: %d\n", level, parentNode->data);
}