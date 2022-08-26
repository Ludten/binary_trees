#include "binary_trees.h"

/**
 * bstsearch - search for a value in a Binary Search Tree
 * recursively
 *
 * @tree: tree
 * @value: values to be searched for
 * Return: pointer to node with value
 */
bst_t *bstsearch(const bst_t *tree, int value)
{
	if (tree == NULL || tree->n == value)
		return ((bst_t *)tree);

	if (tree->n < value)
		return (bst_search(tree->right, value));

	return (bst_search(tree->left, value));
}

/**
 * bst_search - search for a value in a Binary Search Tree
 *
 * @tree: tree
 * @value: values to be searched for
 * Return: pointer to node with value
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);

	return (bstsearch(tree, value));
}
