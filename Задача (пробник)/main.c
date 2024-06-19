#include "define.h"

#ifndef RUN_TEST

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "func.h"

int main(void)
{
    list_t *head=NULL;
    int rc=list_read(&head);
    if (!rc)
    {
        process(head);
        list_print(head);
    }
    
    if (rc)
        printf("ERROR: %d\n",rc);

    list_free(&head);
    return rc;
}

#else
void main_void(void)
{
    
}
#endif

/*
CASE: 
input:
5
5 4 3 2 1
output:
1 4 3 2 5

input:
blah
output:
ERROR: 1

*/