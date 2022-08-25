#include "binary_trees.h"

/**
 * binary_depth - function to recursively
 * calculate the depth of the binary tree
 *
 * @tree: tree
 * Return: -1 or Height
 */
size_t binary_depth(const binary_tree_t *tree)
{
	int pard;

	if (tree == NULL)
		return (-1);

	pard = binary_depth(tree->parent);
	return (pard + 1);
}

/**
 * binary_tree_depth - calculate the depth
 * of the binary tree
 *
 * @tree: tree
 * Return: 0 or Depth
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_depth(tree));
}
