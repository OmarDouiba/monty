#include "main.h"
void f_pall(stack_t **stack, unsigned int line_number)
{
    (void)line_number;
    stack_t *tmp;
    
    tmp = (*stack);
    while(tmp)
    {
        printf("%d\n", tmp->n);
        tmp = tmp->next;
    }
}