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

	if (parent == NULL)
		return (NULL);

	temp = malloc(sizeof(binary_tree_t));
	if (temp == NULL)
		return (NULL);

	temp->n = value;
	temp->left = parent->left;
	temp->right = NULL;
	temp->parent = parent;

	if (parent->left != NULL)
		parent->left->parent = temp;
	parent->left = temp;

	return (temp);
}
