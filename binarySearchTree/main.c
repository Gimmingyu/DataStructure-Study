#include "bst.h"

int main(void)
{
	BinTreeNode	node;
	BinTreeNode	*parent;
	BinTree		*tree;

	node.data = 30;
	tree = createBinTree(node);
	
	node.data = 20;
	pushNodeBT(tree, node);
	
	node.data = 40;
	pushNodeBT(tree, node);

	node.data = 10;
	pushNodeBT(tree, node);

	node.data = 6;
	pushNodeBT(tree, node);

	node.data = 14;
	pushNodeBT(tree, node);

	node.data = 24;
	pushNodeBT(tree, node);


	node.data = 22;
	pushNodeBT(tree, node);

	node.data = 46;
	pushNodeBT(tree, node);

	node.data = 34;
	pushNodeBT(tree, node);


	printf("preorderTraversalBinTree\n");
	preorderTraversalBinTree(tree->pRootNode, 0);
	printf("========================================\n");
	printf("inorderTraversalBinTree\n");
	inorderTraversalBinTree(tree->pRootNode, 0);
	printf("========================================\n");
	printf("levelOrderTraversalBinTree\n");
	levelOrderTraversalBinTree(tree->pRootNode, 0);
	printf("========================================\n");

	system("leaks a.out > leaks_result; cat leaks_result | \
        grep leaked && rm -rf leaks_result");
	return (0);
}
