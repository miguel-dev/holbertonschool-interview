#include "binary_trees.h"
#include <stdlib.h>
#include <stdbool.h>

/**
 * depth - Calculates the depth of the tree.
 * 
 * @root: Root of tree.
 *
 * Return: Depth of tree.
 */
int calculate_depth(heap_t *root)
{
	int depth = 1;
	heap_t *iterator;

	iterator = root;
	while (iterator->left)
	{
		iterator = iterator->left;
		depth++;
	}
	return (depth);
}

/**
 * swap - If there is a Max heap violation it swaps the nodes.
 *
 * @root: Addess of root node.
 * @new_node: node to start checkin for Max heap violations.
 *
 *
 */
/*void swap(heap_t *root, heap_t *node)
{
	heap_t *temp;

	while (node->parent) 
	{
		if (node->n > node->parent)
		{
			temp = node->parent;
			node->parent = node;
			node = temp;
		}
		node = node->parent;
	}
}*/

/**
 * find_parent - Finds the most suitable parent node to mantain Max Heap..
 *
 * @root: Address to root node of Heap.
 * @node: Node to be inserted.
 */
void find_parent(heap_t *root, heap_t *node, heap_t **parent)
{
	if (root->left && root->right)
	{
		find_parent(root->left, node, parent);
		find_parent(root->right, node, parent);
	}
	else
	{
		if (root->left == NULL || root->right == NULL)
		{
			*parent = root;
		}
	}
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
	heap_t *parent = NULL;

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
		find_parent(*root, new_node, &parent);
		if (parent->left == NULL)
		{
			parent->left = new_node;
		}
		else if (parent->right == NULL)
		{
			parent->right = new_node;
		}
		new_node->parent = parent;
		/*swap(*root, new_node);*/
	}
	return (new_node);
}
