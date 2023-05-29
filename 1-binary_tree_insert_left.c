#include <stdlib.h>
#include <stdio.h>

/* Binary tree node structure */
typedef struct binary_tree_s {
    int value;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
} binary_tree_t;

/**
 * binary_tree_insert_left - Inserts a node as the left-child of another node.
 * @parent: Pointer to the node to insert the left-child in.
 * @value: Value to store in the new node.
 *
 * Return: Pointer to the created node, or NULL on failure or if parent is NULL.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
    binary_tree_t *new_node;

    if (parent == NULL)
    {
        fprintf(stderr, "Error: Parent node is NULL\n");
        return NULL;
    }

    new_node = malloc(sizeof(binary_tree_t));
    if (new_node == NULL)
    {
        perror("Failed to allocate memory for new node");
        return NULL;
    }

    new_node->value = value;
    new_node->parent = parent;
    new_node->right = NULL;

    if (parent->left != NULL)
    {
        new_node->left = parent->left;
        parent->left->parent = new_node;
    }
    else
    {
        new_node->left = NULL;
    }

    parent->left = new_node;

    return new_node;
}

