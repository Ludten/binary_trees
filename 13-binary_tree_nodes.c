#include "binary_trees.h"

/**
 * binary_tree_nodes - counts the nodes with at
 * least 1 child
 *
 * @tree: tree
 * Return: 0 or number of nodes
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	int res;

	if (tree == NULL)
		return (0);

	res = 0;
	if (tree->left == NULL && tree->right == NULL)
		return (0);
	if ((tree->left != NULL && tree->right == NULL) ||
	(tree->left == NULL && tree->right != NULL))
		res++;
	if (tree->left != NULL && tree->right != NULL)
		res++;

	res += (binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));
	return (res);
}
