#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_node - Creates a binary tree node.
 *
 * @parent: Pointer to parent node of binary tree
 * @value: Value of new node.
 *
 * Return: Pointer to new node, or NULL if it failed.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	new_node = malloc(sizeof(binary_tree_t));
	if (!new_node)
	{
		return NULL;
	}

	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->n = value;

	return new_node;
}
