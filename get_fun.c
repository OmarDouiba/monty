#include "monty.h"
/**
 * get_fun - Function that selects the appropriate function to perform
 *           the operation requested by a given opcode.
 *
 * @s: The opcode string to match.
 *
 * Return: A pointer to the corresponding function, or NULL if not found.
 */
void (*get_fun(char *s))(stack_t **stack, unsigned int line_number)
{
    (void)line_number;
    instruction_t op_code[] = {
        {"push", f_push},
        {"pall", f_pall},
        {"pop", f_pop},
        {"pint", f_pint},
        {"print_stack", print_stack},
        {NULL, NULL}
    };
    int i = 0;
    
    while (op_code[i].opcode)
    {
        if (strncmp(op_code[i].opcode, s, strlen(op_code[i].opcode)) == 0)
        {
            return (op_code[i].f);
        }
        i++;
    }
    return (NULL);
}