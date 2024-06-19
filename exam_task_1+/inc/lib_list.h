#ifndef LIB_LIST_H
#define LIB_LIST_H

#include <stdio.h>
#include <stdlib.h>

#include "const_struct.h"

void free_list(node_t *Head);
void print_list(node_t Head);
int add_elem_list(node_t *Head, int a, int b, int c, int num);

#endif // LIB_LIST_H
