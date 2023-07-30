#include <stdlib.h>
#include <stdio.h>

#include "node.h"

void insert_end(struct node **root, int value)
{
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL)
    {
        exit(1);
    }

    new_node->next = NULL;
    new_node->data = value;

    if (*root == NULL)
    {
        *root = new_node;
        return;
    }

    node *curr = *root;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }

    curr->next = new_node;
}

void insert_beginning(struct node **root, int value)
{
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL)
    {
        exit(1);
    }

    new_node->data = value;
    new_node->next = *root;

    *root = new_node;
}

void insert_after(struct node *curr_node, int value)
{
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL)
    {
        exit(1);
    }

    new_node->data = value;
    new_node->next = curr_node->next;
    curr_node->next = new_node;
}

void insert_sorted(struct node **root, int value)
{
    if (*root == NULL || (*root)->data >= value)
    {
        insert_beginning(root, value);
        return;
    }

    node *curr = *root;
    while (curr->next != NULL)
    {
        if (curr->next->data >= value)
            break;

        curr = curr->next;
    }

    insert_after(curr, value);
}

void remove_element(struct node **root, int value)
{
    if (*root == NULL)
        return;

    if ((*root)->data == value)
    {
        node *to_remove = *root;
        *root = (*root)->next;
        free(to_remove);
        return;
    }

    for (node *curr = *root; curr->next != NULL; curr = curr->next)
    {
        if (curr->next->data == value)
        {
            node *to_remove = curr->next;
            curr->next = curr->next->next;
            free(to_remove);
            return;
        }
    }
}

void reverse(struct node **root)
{
    node *prev = NULL;
    node *curr = *root;

    while (curr != NULL)
    {
        node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    *root = prev;
}

int has_loops(node *root)
{
    node *slow = root;
    node *fast = root;

    while (slow != NULL && fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            return 1;
        }
    }

    return 0;
}

int count(node *root)
{
    int c = 0;
    for (node *curr = root; curr != NULL; curr = curr->next)
    {
        c++;
    }

    return c;
}

int count_rec(node *curr)
{
    if (curr == NULL)
    {
        return 0;
    }

    return 1 + count_rec(curr->next);
}

void print(struct node *root)
{
    printf("----------------------------------------------\n");
    for (node *curr = root; curr != NULL; curr = curr->next)
    {
        printf("%d\n", curr->data);
    }
    printf("----------------------------------------------\n");
}

void dealloc(struct node **root)
{
    node *curr = *root;
    while (curr != NULL)
    {
        node *aux = curr;
        curr = curr->next;
        free(aux);
    }

    *root = NULL;
}