#include "binary_trees.h"

/**
 * depth - calculate the depth of a node from root
 *
 * @node: node
 * Return: depth
 */
int depth(const binary_tree_t *node)
{
	int d = -1;

	while (node)
	{
		++d;
		node = node->parent;
	}
	return (d);
}

/**
 * binary_trees_ancestor - finds the lowest common
 * ancestor of two nodes
 *
 * @first: first node
 * @second: second node
 * Return: pointer to the lowest common ancestor
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
	int d1, d2, diff;

	if (first == NULL || first->parent == NULL)
		return (NULL);
	if (second == NULL || second->parent == NULL)
		return (NULL);

	d1 = depth(first);
	d2 = depth(second);
	diff = d1 - d2;

	if (diff < 0)
	{
		while (diff++)
			second = second->parent;
	}
	else if (diff > 0)
	{
		while (diff--)
			first = first->parent;
	}

	while (first && second)
	{
		if (first == second)
			return ((binary_tree_t *)first);
		first = first->parent;
		second = second->parent;
	}
	return (NULL);
}
