#include "main.h"
void f_pint(stack_t **stack, unsigned int line_number)
{
    (void)line_number;
    printf("%d\n", (*stack)->n);
}