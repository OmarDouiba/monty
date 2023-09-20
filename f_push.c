#include "main.h"
/**
 * f_push - Pushes an integer onto the stack.
 * @stack: A pointer to a pointer to the stack.
 * @line_number: The line number of the push instruction.
 *
 * Description: This function pushes an integer onto the stack data structure.
 * It takes a double pointer to the stack and the line number where the push
 * operation occurs as arguments.
 */
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