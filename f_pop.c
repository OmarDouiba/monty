#include "main.h"
void f_pop(stack_t **stack, unsigned int line_number)
{
    (void)line_number;

    if (((*stack)->next))
    {
        *stack = (*stack)->next;
        free((*stack)->prev);
    }
    else
    {
        free(*stack);
        (*stack) = NULL;
    }
}