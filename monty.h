#ifndef MONTY_H
#define MONTY_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFF_SIZE 1024
#define line_size 128

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


void (*check_opcode(char *str))(stack_t **, unsigned int);
void open_file(char *filename);
int interprete_opcode(stack_t **stack, char **str_arr, int line_no);
void push_func(stack_t **stack, unsigned int line_number);
void pall_func(stack_t **stack, unsigned int line_number);
void pint_func(stack_t **stack, unsigned int line_number);
void pop_func(stack_t **stack, unsigned int line_number);
void swap_func(stack_t **stack, unsigned int line_number);
void add_func(stack_t **stack, unsigned int line_number);
void nop_func(stack_t **stack, unsigned int line_number);
void sub_func(stack_t **stack, unsigned int line_number);
void div_func(stack_t **stack, unsigned int line_number);
void mul_func(stack_t **stack, unsigned int line_number);
void mod_func(stack_t **stack, unsigned int line_number);

char *_strsep(char **str, char *delim);
ssize_t read_line(char **lineptr, ssize_t *bufsize, FILE *stream);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *compose_err(char *str, unsigned int num);
void malloc_error(void);
void write_err(char *str);
char *compose_err_str(char *str, char *filename);
char **split_string(char *line);
char *_strdup(char *str);
int check_4_alpha(char *str);
int str_to_int(char *input);

#endif /* MONTY_H */
