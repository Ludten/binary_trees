#include "binary_trees.h"

/**
 * minValueNode - minimum node value
 *
 * @node: node
 * Return: pointer to mininode
 */
bst_t *minValueNode(bst_t *node)
{
	bst_t *curr = node;

	while (curr && curr->left != NULL)
		curr = curr->left;

	return (curr);
}

/**
 * bst_remove - remove a node in a binary search
 * tree
 *
 * @root: root
 * @value: value
 * Return: pointer to new root
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL)
		{
			temp = root->right;
			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			temp = root->left;
			free(root);
			return (temp);
		}
		temp = minValueNode(root->right);
		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);
	}
	return (root);
}
