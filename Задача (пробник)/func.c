#include "define.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "func.h"

list_t *list_new(void)
{
    return (list_t*)malloc(sizeof(list_t));
}

void list_free(list_t **head)
{
    list_t *node=*head;
    while (node)
    {
        list_t *tmp=node;
        node=node->next;
        free(tmp);
    }
    *head=NULL;
}

int list_prepend(list_t **head, int num)
{
    list_t *new=list_new();
    if (!new)
        return ERR_MEM;
        
    new->num=num;
    new->next=*head;
    *head=new;
    
    return OK;
}

int list_append(list_t **head, int num)
{
    list_t *new=list_new();
    if (!new)
        return ERR_MEM;
        
    new->num=num;
    new->next=NULL;
    
    if (*head==NULL)
    {
        *head=new;
    }
    else
    {
        list_t *node=*head;
        while(node->next)
            node=(node)->next;
        node->next=new;
    }
    
    return OK;
}

// return pointer to min element
static list_t *find_min(list_t *head)
{
    assert(head);
    list_t *min=head;
    while (head->next)
    {
        head=head->next;
        if (min->num > head->num)
            min=head;
    }
    return min;
}

static void swap(list_t *l1, list_t *l2)
{
    int tmp=l1->num;
    l1->num=l2->num;
    l2->num=tmp;
}

int list_read(list_t **phead)
{
    int size;
    if (scanf("%d",&size)!=1)
        return ERR_IO_RANGE; // ERR_IO
    if (size<=0)
        return ERR_IO_RANGE; // ERR_RANGE
    
    int rc=OK;
    list_t *head=NULL;
    for (int i=0; i<size; i++)
    {
        int num;
        rc=scanf("%d",&num);

        if (rc==1)
        {
            rc=list_append(&head,num);
        }
        else
            rc=ERR_IO_RANGE;
    }
    if (rc)
    {
        list_free(&head);
    }
    
    if (!head)
        return ERR_IO_RANGE;
    
    *phead=head;
    
#ifdef MY_DEBUG
    list_print(head);
#endif
    
    return rc;
}

void list_print(list_t *head)
{
    if (!head)
        return;
        
    while (head)
    {
        printf("%d ", head->num);
        head=head->next;
    }
    printf("\n");
}

void process(list_t *head)
{
    list_t *min=find_min(head);
    swap(min,head);
}






























