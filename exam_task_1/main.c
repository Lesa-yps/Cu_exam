#include <stdio.h>
#include <stdlib.h>

// коды возврата
#define OK 0
#define ERR_READ 1
#define ERR_MEM 2

typedef struct Node* node_t;

// структура - элемент списка
struct Node
{
    node_t next;
    int num; // номер элемента по порядку его ввода
    int a;
    int b;
    int c;
};

void free_node(node_t *node1)
{
    if (*node1 != NULL)
    {
        free(*node1);
        *node1 = NULL;
    }
}

void free_list(node_t *Head)
{
    node_t *cur = Head;
    while (*cur != NULL)
    {
        node_t *tmp = cur;
        *cur = (*cur)->next;
        free_node(tmp);
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

int add_elem_list(node_t *Head, int a, int b, int c, int num);

int main(void)
{
    int rc = OK;
    int rc_scanf;
    int a, b, c;
    node_t Head = NULL;
    int num = 0;
    // чтение элементов списка и добавление в него
    while (rc == OK && (rc_scanf = scanf("%d%d%d", &a, &b, &c)) == 3)
    {
        rc = add_elem_list(&Head, a, b, c, num);
        num++;
    }
    // обработка ошибок
    if (rc_scanf == 1 || rc_scanf == 2)
        rc = ERR_READ;
    // вывод результата
    if (rc == OK)
        print_list(Head);
    free_list(&Head);
    return rc;
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
