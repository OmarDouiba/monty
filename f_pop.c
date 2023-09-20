#include "monty.h"
/**
 * f_pop - Removes the top element from the stack.
 * @stack: A pointer to a pointer to the stack.
 * @line_number: The line number of the pop instruction.
 *
 * Description: This function removes the top element from the stack data
 * structure. It takes a double pointer to the stack and the line number where
 * the pop operation occurs as arguments.
 */
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