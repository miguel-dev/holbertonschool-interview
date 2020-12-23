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
	new_node = binary_tree_node(*root, value);

	if (!root)
	{
		root = new_node;
	}

	return (new_node);
}
