#include "binary_trees.h"

/**
 * binary_height - function to recursively
 * calculate the height of the binary tree
 *
 * @tree: tree
 * Return: -1 or Height
 */
size_t binary_height(const binary_tree_t *tree)
{
	int lefth, righth;

	if (tree == NULL)
		return (-1);

	lefth = binary_height(tree->left);
	righth = binary_height(tree->right);

	if (lefth >= righth)
	{
		return (lefth + 1);
	}
	return (righth + 1);
}

/**
 * binary_tree_height - calculate the height
 * of the binary tree
 *
 * @tree: tree
 * Return: 0 or Height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_height(tree));
}
