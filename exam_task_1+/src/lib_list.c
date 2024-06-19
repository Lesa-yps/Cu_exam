#include "lib_list.h"

void free_node(node_t *node1)
{
    if (*node1 != NULL)
    {
        //printf("Free %d %d %d num = %d\n", (*node1)->a, (*node1)->b, (*node1)->c, (*node1)->num);
        free(*node1);
        *node1 = NULL;
    }
}

void free_list(node_t *Head)
{
    node_t *cur = Head;
    while (*cur != NULL)
    {
        node_t *tmp = &((*cur)->next);
        //printf("CUR %d %d %d num = %d\n", (*cur)->a, (*cur)->b, (*cur)->c, (*cur)->num);
        free_node(cur);
        *cur = *tmp;
    }
}

void print_list(node_t Head)
{
    node_t cur = Head;
    while (cur != NULL)
    {
        printf("%d %d %d\n", cur->a, cur->b, cur->c);
        cur = cur->next;
    }
}

int create_node(node_t *new_node, int a, int b, int c, int num)
{
    int rc = OK;
    *new_node = calloc(1, sizeof(struct Node));
    if (*new_node == NULL)
        rc = ERR_MEM;
    else
    {
        (*new_node)->a = a;
        (*new_node)->b = b;
        (*new_node)->c = c;
        (*new_node)->num = num;
        (*new_node)->next = NULL;
        //printf("Create %d %d %d num = %d\n", a, b, c, num);
    }
    return rc;
}

void insert_after(node_t *Head, node_t new_node, int num_after)
{
    if (*Head == NULL)
        *Head = new_node;
    else if ((*Head)->num == num_after)
    {
        new_node->next = *Head;
        *Head = new_node;
    }
    else
    {
        node_t cur = *Head;
        while (cur->next != NULL && (cur->next)->num != num_after)
            cur = cur->next;
        new_node->next = cur->next;
        cur->next = new_node;
    }
}

int add_elem_list(node_t *Head, int a, int b, int c, int num)
{
    int rc = OK;
    node_t new_node = NULL;
    rc = create_node(&new_node, a, b, c, num);
    if (rc == OK)
    {
        if (b == c)
            insert_after(Head, new_node, 0);
        else
            insert_after(Head, new_node, num);
    }
    return rc;
}
