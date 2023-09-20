#include "main.h"
/**
 * f_pall - Prints all the elements of the stack.
 * @stack: A pointer to a pointer to the stack.
 * @line_number: The line number of the pall instruction.
 *
 * Description: This function prints all the elements of the stack data structure,
 * starting from the top. It takes a double pointer to the stack and the line
 * number where the pall operation occurs as arguments.
 */
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