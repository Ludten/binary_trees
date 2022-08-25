#include "binary_trees.h"

/**
 * binary_tree_size - calculates the size of
 * the binary tree
 *
 * @tree: tree
 * Return: 0 or size
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_size(tree->left) + 1 + binary_tree_size(tree->right));
}

/**
 * binary_tree_is_perfect - check if a binary tree
 * is perfect
 *
 * @tree: tree
 * Return: 0 or 1
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int len;

	if (tree == NULL)
		return (0);

	len = binary_tree_size(tree);

	if ((len & (len + 1)) == 0)
		return (1);
	return (0);
}
