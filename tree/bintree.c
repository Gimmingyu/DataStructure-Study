#include "./bintree.h"

BinTree		*makeBinTree(BinTreeNode rootNode)
{
	BinTree		*newTree = calloc(1, sizeof(BinTree));
	BinTreeNode	*root = calloc(1, sizeof(BinTreeNode));

	root->data = rootNode.data;
	root->visited = 0;
	newTree->pRootNode = root;
	return (newTree);
}

BinTreeNode	*getRootNodeBT(BinTree *pBinTree)
{
	if (!pBinTree)
		return  (NULL);
	printf("root node data = %c\n", pBinTree->pRootNode->data);
	return (pBinTree->pRootNode);
}

// 부모노드에 자식 노드를 왼쪽에 넣어주고 자식노드를 리턴
BinTreeNode	*insertLeftChildNodeBT(BinTreeNode *pParentNode, BinTreeNode element)
{
	if (!pParentNode)
		return (NULL);
	BinTreeNode	*newNode = calloc(1, sizeof(BinTreeNode));
	newNode->data = element.data;
	newNode->visited = 0;
	pParentNode->pLeftChild = newNode;
	return (newNode);
}

// 부모노드에 자식 노드를 오른쪽에 넣어주고 자식노드를 리턴
BinTreeNode	*insertRightChildNodeBT(BinTreeNode *pParentNode, BinTreeNode element)
{
	if (!pParentNode)
		return (NULL);
	BinTreeNode	*newNode = calloc(1, sizeof(BinTreeNode));
	newNode->data = element.data;
	newNode->visited = 0;
	pParentNode->pRightChild = newNode;
	return (newNode);
}

// 노드의 왼쪽 자식노드를 리턴
BinTreeNode	*getLeftChildNodeBT(BinTreeNode *pNode)
{
	if (!(pNode->pLeftChild))
		return (NULL);
	return (pNode->pLeftChild);
}

// 노드의 오른쪽 자식노드를 리턴
BinTreeNode	*getRightChildNodeBT(BinTreeNode* pNode)
{
	if (!(pNode->pRightChild))
		return (NULL);
	return (pNode->pRightChild);
}

// 노드 하나를 삭제 
void	deleteBinTreeNode(BinTreeNode* pNode)
{
	pNode->pLeftChild = NULL;
	pNode->pRightChild = NULL;
	free(pNode);
}

// 트리 전체를 삭제
void	deleteBinTree(BinTree *pBinTree)
{
	if (!pBinTree)
		return ;
	free_leafNode(pBinTree->pRootNode);
	free(pBinTree);
}

void	free_leafNode(BinTreeNode *parentNode)
{
	if (parentNode->pLeftChild)
		free_leafNode(parentNode->pLeftChild);
	if (parentNode->pRightChild)
		free_leafNode(parentNode->pRightChild);
	free(parentNode);
}