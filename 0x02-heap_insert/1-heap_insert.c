#include "binary_trees.h"
#include <stdlib.h>

/**
 * heap_insert - Inserts a value into a Max Binary Heap.
 *
 * @root: Address to root node of Heap.
 * @value: Value to assign to the node to be inserted.
 *
 * Return: Pointer to the inserted node, or NULL if it fails.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	binary_tree_t *new_node;

	new_node = malloc(sizeof(binary_tree_t));
	if (!new_node)
	{
		return (NULL);
	}

	new_node->parent = NULL;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->n = value;

	if (*root == NULL)
	{
		*root = new_node;
	}

	return (new_node);
}
