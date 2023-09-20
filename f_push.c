#include "main.h"
void f_push(stack_t **stack, unsigned int line_number)
{
    (void)line_number;
    stack_t *new;

    new = malloc(sizeof(stack_t));
    if (!new)
    {
        dprintf(2, "Error: malloc failed");
        exit(EXIT_FAILURE);
    }
    new->prev = NULL;
    new->n = value;
    new->next = NULL;
    if (*stack == NULL)
    {
        (*stack) = new;
    }
    else
    {
        new->next = (*stack);
        (*stack)->prev = new;
        (*stack) = new;
    }
}