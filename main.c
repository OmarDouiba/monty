#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

int value = 0;
unsigned int line_number = 0;

int main(int argc, char *argv[])
{
    void (*fptr)();
    FILE *fp;
    char *buff = NULL, *arr_buf[2];
    size_t  n;
    stack_t *stack = NULL;
   
    
    if (!(argc == 2))
    {
        dprintf(2, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    fp = fopen(argv[1], "r");
    if (!fp)
    {
        dprintf(2, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    while (getline(&buff, &n, fp) != -1)
    {
        arr_buf[0] = strtok(buff, " \t\n");
        // if (arr_buf[0] == " ")
        // {
        //     line_number++;
        //     continue;
        // }
        
       
        if (strncmp("push", arr_buf[0], 4) == 0)
        {
            line_number++;
            arr_buf[1] = strtok(NULL, " \t\n");
            // printf("%s\n",  arr_buf[1]);
            value = str_to_num(arr_buf[1]);
            printf("%d\n", value);
            // if (value == 0)
            // {
            //     dprintf(2, "L%d: unknown instruction is not a number\n", line_number);
            //     exit(EXIT_FAILURE);
            // }
        }
        fptr = get_fun(arr_buf[0]);
        if (!fptr)
        {
            dprintf(2, "L%d: unknown instruction %s\n", line_number, arr_buf[0]);
            exit(EXIT_FAILURE);
        }
        else
        {
            (*fptr)(&stack, line_number);
        }
    }
    fclose(fp);
    free(buff), buff = NULL;
}