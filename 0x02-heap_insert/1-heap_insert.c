#include "binary_trees.h"
#include <stdlib.h>

/**
 * depth - Calculates the depth of the tree.
 * 
 * @root: Root of tree.
 *
 * Return: Depth of tree.
 */
int calculate_depth(heap_t *root)
{
	int depth = 0;
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
 * @node: node to start checkin for Max heap violations.
 */
/*void swap(heap_t **node)
{
	heap_t *iterator = *node;
	heap_t *temp, *father, *grandfather;

	while (iterator->parent)
	{
		if (iterator->n > iterator->parent->n)
		{
			grandfather = iterator->parent->parent;
			father = iterator->parent;

			temp = iterator->parent;
			iterator->parent = iterator;
			iterator = temp;
			
			iterator->parent = grandfather;

			if (grandfather && grandfather->left == father)
			{
				grandfather->left = iterator;
			}
			else if (grandfather && grandfather->right == father)
			{
				grandfather->right = iterator;
			}

			if (father->left == iterator)
			{

				temp = iterator->left;
				iterator->left = father;
				father->left = temp;

				temp = father->right;
				father->right = iterator->right;
				iterator->right = temp;
			}
			else if (father->right == iterator)
			{
				temp = iterator->right;
				iterator->right = father;
				father->right = temp;

				temp = father->left;
				father->left = iterator->left;
				iterator->left = temp;
			}
		}
	}
}*/

/**
 * find_parent - Finds the most suitable parent node to mantain Max Heap..
 *
 * @root: Address to root node of Heap.
 * @node: Node to be inserted.
 * @parent: Node most suitable to be parent.
 * @depth: Total depth.
 * @present_depth: Actual depth.
 */
void find_parent(heap_t *root, heap_t *node, heap_t **parent, int* depth, int* present_depth)
{
	(*present_depth)++;


	if ((root->left == NULL || root->right == NULL))
	{
		*parent = root;
	}
	else if (root->left && root->right)
	{
		find_parent(root->left, node, parent, depth, present_depth);	
		if (parent)
			return;

		find_parent(root->right, node, parent, depth, present_depth);
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
	int depth = 0;
	int present_depth = 0;

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
		depth = calculate_depth(*root);

		find_parent(*root, new_node, &parent, &depth, &present_depth);

		if (parent->left == NULL)
		{
			parent->left = new_node;
		}
		else if (parent->right == NULL)
		{
			parent->right = new_node;
		}
		new_node->parent = parent;
		/*swap(&new_node);*/
	}
	return (new_node);
}
