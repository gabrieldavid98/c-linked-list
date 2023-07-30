#ifndef NODE_H_
#define NODE_H_

typedef struct node
{
    int data;
    struct node *next;
} node;

void insert_end(struct node **root, int value);
void insert_beginning(struct node **root, int value);
void insert_after(struct node *curr_node, int value);
void insert_sorted(struct node **root, int value);

void remove_element(struct node **root, int value);
void reverse(struct node **root);

int has_loops(node *root);
int count(node *root);
int count_rec(node *curr);

void print(struct node *root);
void dealloc(struct node **root);

#endif // NODE_H_