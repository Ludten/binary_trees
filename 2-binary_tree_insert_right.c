#include "binary_trees.h"

/**
 * binary_tree_insert_right - insert under right node
 *
 * @parent: parent node
 * @value: data
 * Return: pointer to new node
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *temp;

	if (parent == NULL)
		return (NULL);

	temp = malloc(sizeof(binary_tree_t));
	if (temp == NULL)
		return (NULL);

	temp->n = value;
	temp->left = NULL;
	temp->right = NULL;
	temp->parent = parent;

	if (parent->right != NULL)
	{
		temp->right = parent->right;
		parent->right->parent = temp;
	}
	parent->right = temp;

	return (temp);
}
