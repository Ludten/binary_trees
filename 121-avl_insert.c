#include "binary_trees.h"

/**
 * _height - function to recursively
 * calculate the height of the binary tree
 *
 * @tree: tree
 * Return: -1 or Height
 */
size_t _height(const binary_tree_t *tree)
{
	int lefth, righth;

	if (tree == NULL)
		return (-1);

	lefth = _height(tree->left);
	righth = _height(tree->right);

	if (lefth >= righth)
	{
		return (lefth + 1);
	}
	return (righth + 1);
}

/**
 * avl_insert - Inserts a value into an AVL tree.
 * @tree: A double pointer to the root node of the AVL tree to insert into.
 * @value: The value to insert into the AVL tree.
 *
 * Return: A pointer to the inserted node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(*tree, value);
		return (*tree);
	}
	if (value < (*tree)->n)
	{
		if ((*tree)->left != NULL)
			return (avl_insert(&(*tree)->left, value));
		(*tree)->left = binary_tree_node(*tree, value);
		if ((_height((*tree)->left) - _height((*tree)->right)) == 2)
		{
			if ((*tree)->left->n > value)
				*tree = binary_tree_rotate_left(*tree);
			else
			{
				(*tree)->right = binary_tree_rotate_right((*tree)->right);
				return (binary_tree_rotate_left(*tree));
			}
		}
		return (*tree)->left;
	}
	if (value > (*tree)->n)
	{
		if ((*tree)->right != NULL)
			return (avl_insert(&(*tree)->right, value));
		(*tree)->right = binary_tree_node(*tree, value);
		return (*tree)->right;
	}

	return(*tree);
}
