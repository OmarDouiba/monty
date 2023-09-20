#ifndef HEADER_H
#define HEADRE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

extern int value;
extern unsigned int line_number;

typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void (*get_fun(char *s))(stack_t **stack, unsigned int line_number);

void f_push(stack_t **stack, unsigned int line_number);
void f_pall(stack_t **stack, unsigned int line_number);
void f_pint(stack_t **stack, unsigned int line_number);
void f_pop(stack_t **stack, unsigned int line_number);
void print_stack(stack_t **stack, unsigned int line_number);
int str_to_num(char *s);


#endif