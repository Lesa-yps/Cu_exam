#ifndef CONST_STRUCT_H
#define CONST_STRUCT_H

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

#endif // CONST_STRUCT_H
