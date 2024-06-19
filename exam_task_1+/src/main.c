#include <stdio.h>

#include "const_struct.h"
#include "lib_list.h"

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
