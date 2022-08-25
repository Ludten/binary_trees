#include "binary_trees.h"

/**
 * binary_height - function to recursively
 * calculate the height of the binary tree
 *
 * @node: tree node
 * Return: 0 or Height
 */
size_t binary_height(const binary_tree_t *node)
{
	int lheight, rheight;

	if (node == NULL)
		return (0);

	lheight = binary_height(node->left);
	rheight = binary_height(node->right);

	if (lheight > rheight)
		return (lheight + 1);
	else
		return (rheight + 1);

}

/**
 * printCurrentLevel - print current level
 *
 * @tree: tree
 * @level: tree level
 * @func: print func
 */
void printCurrentLevel(const binary_tree_t *tree, size_t level,
void (*func)(int))
{
	if (tree == NULL)
		return;
	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		printCurrentLevel(tree->left, level - 1, func);
		printCurrentLevel(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_levelorder - level order traversal
 *
 * @tree: entire tree
 * @func: function to call each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t h, i;

	if (tree == NULL)
		return;

	if (func == NULL)
		return;

	h = binary_height(tree);
	for (i = 1; i <= h; i++)
		printCurrentLevel(tree, i, func);
}
