#include <stdio.h>
#include <stdlib.h>

#include "node.h"

int main(void)
{
    node *root = NULL;

    insert_end(&root, 1);
    insert_end(&root, 1);
    insert_end(&root, 3);
    insert_end(&root, 6);
    insert_end(&root, 7);

    print(root);

    printf("Linked list has %d elements\n", count_rec(root));

    dealloc(&root);

    return 0;
}
