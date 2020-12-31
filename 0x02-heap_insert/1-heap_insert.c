#include "binary_trees.h"
#include <stdlib.h>

/**
 * heap_insert2 - Inserts a value into a Max Binary Heap.
 *
 * @root: Address to root node of Heap.
 * @node: Node to be inserted.
 *
 * Return: Pointer to the inserted node, or NULL if it fails.
 */
heap_t *heap_insert2(heap_t *root, heap_t *node)
{
	if (root->left == NULL)
	{
		root->left = node;
		node->parent = root;
	}
	else if (root->right == NULL)
	{
		root->right = node;
		node->parent = root;
	}
	else
	{
		node = heap_insert2(root->left, node);
		if (node)
		{
			return (node);

		}

		node = heap_insert2(root->right, node);
		if (node)
		{
			return (node);
		}
	}
	return (node);
}


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
	heap_t *new_node;

	new_node = malloc(sizeof(heap_t));
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
	else
	{
		new_node = heap_insert2(*root, new_node);
	}

	return (new_node);
}
