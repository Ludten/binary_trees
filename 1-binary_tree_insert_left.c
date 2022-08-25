#include "binary_trees.h"

/**
 * binary_tree_insert_left - insert under left node
 *
 * @parent: parent node
 * @value: data
 * Return: pointer to new node
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *temp;

	temp = malloc(sizeof(binary_tree_t));
	if (temp == NULL)
		return (NULL);
	if (parent == NULL)
		return (NULL);

	temp->n = value;
	temp->left = NULL;
	temp->right = NULL;
	temp->parent = parent;

	if (parent->left != NULL)
	{
		parent->left->parent = temp;
		temp->left = parent->left;
	}
	parent->left = temp;

	return (temp);
}
