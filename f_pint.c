#include "monty.h"
/**
 * f_pint - Prints the top element of the stack.
 * @stack: A pointer to a pointer to the stack.
 * @line_number: The line number of the pint instruction.
 *
 * Description: This function prints the top element of the stack data structure.
 * It takes a double pointer to the stack and the line number where the pint
 * operation occurs as arguments.
 */
void f_pint(stack_t **stack, unsigned int line_number)
{
    (void)line_number;
    printf("%d\n", (*stack)->n);
}