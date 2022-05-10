#include "bintree.h"

int main(void)
{
	BinTreeNode	node;
	BinTreeNode	*parent;
	BinTreeNode	*right;
	BinTreeNode	*left;
	BinTree		*tree;

	node.data = 'A';
	tree = makeBinTree(node);
	parent = getRootNodeBT(tree);

	node.data = 'B';
	left = insertLeftChildNodeBT(parent, node);

	node.data = 'C';
	right = insertRightChildNodeBT(parent, node);

	node.data = 'D';
	insertLeftChildNodeBT(left, node);

	node.data = 'E';
	insertRightChildNodeBT(left, node);

	node.data = 'F';
	insertLeftChildNodeBT(right, node);

	node.data = 'G';
	insertRightChildNodeBT(right, node);
	
	printf("preorderTraversalBinTree\n");
	preorderTraversalBinTree(parent, 0);
	printf("========================================\n");
	printf("inorderTraversalBinTree\n");
	inorderTraversalBinTree(parent, 0);
	printf("========================================\n");
	printf("levelOrderTraversalBinTree\n");
	levelOrderTraversalBinTree(parent, 0);
	printf("========================================\n");

	system("leaks a.out > leaks_result; cat leaks_result | \
        grep leaked && rm -rf leaks_result");
	return (0);
}