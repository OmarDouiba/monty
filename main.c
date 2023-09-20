#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

int value = 0;
unsigned int line_number = 0;

int main(int argc, char *argv[])
{
    char *buff = NULL, *arr_buff[2];
    size_t n = 0;
    FILE *fp;
    void (*fptr)();
    stack_t *stack = NULL;

    if (argc != 2)
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
        arr_buff[0] = strtok(buff, " \t\n");
        if (arr_buff[0] == "#")
        {
            line_number++;
            continue;
        }
        if(strcmp(arr_buff[0], "push") == 0)
        {
            arr_buff[1] = strtok(NULL, " \t\n");
            value = atoi(arr_buff[1]);
        }
        fptr = get_fun(arr_buff[0]);
        if (fptr)
        {
            (*fptr)(&stack, line_number);
        }
        // else
        // {
        //     dprintf(2, "L%d: unknown instruction %s\n", line_number, arr_buff[0]);
        //     exit(EXIT_FAILURE);
        // }
    }
    fclose(fp);
    free(buff), buff = NULL;
    return (0);
}