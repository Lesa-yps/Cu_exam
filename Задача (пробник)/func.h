#ifndef FUNC_H__
#define FUNC_H__

typedef struct list_s list_t;
struct list_s
{
    int num;
    list_t *next;
};

list_t *list_new(void);
void list_free(list_t **head);

int list_prepend(list_t **head, int num);
int list_append(list_t **head, int num);

int list_read(list_t **head);
void list_print(list_t *head);

void process(list_t *head);


#endif
