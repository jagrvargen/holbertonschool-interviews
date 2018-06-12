#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"
#include "search_algos.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full.
 *
 * @tree: A pointer to the root node of a binary tree.
 *
 * Return: An integer 1 if tree is full, 0 if not full or tree == NULL
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int search;

	if (!tree)
		return (0);

	if ((tree->left && !tree->right) || (tree->right && !tree->left))
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	if (tree->right && tree->left)
	{
		search = binary_tree_is_full(tree->left) &&
			binary_tree_is_full(tree->right);
		return (search);
	}

	return (0);
}
