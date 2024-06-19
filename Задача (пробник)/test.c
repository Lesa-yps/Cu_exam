#include "define.h"

#ifdef RUN_TEST

#include <stdio.h>

#include "func.h"


int main(void)
{
    printf("Running tests...\n");
    
    printf("Done\n");
    return 0;
}

#else
void main_void(void)
{
    
}
#endif
