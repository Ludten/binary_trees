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
