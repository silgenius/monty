#ifndef MONTY_H
#define MONTY_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFF_SIZE 1024
#define line_size 64

/* mode - indicates stack (1) or queue (0) operation */
extern int mode;

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
	void (*f)(stack_t **stack, unsigned int line_number, char *data_n);
} instruction_t;


void (*check_opcode(char *str))(stack_t **, unsigned int, char *);
void open_file(char *filename);
int interprete_opcode(stack_t **stack, char **str_arr, int line_no);

void push_func(stack_t **stack, unsigned int line_number, char *data_n);
void pall_func(stack_t **stack, unsigned int line_number, char *data_n);
void pint_func(stack_t **stack, unsigned int line_number, char *data_n);
void pop_func(stack_t **stack, unsigned int line_number, char *data_n);
void swap_func(stack_t **stack, unsigned int line_number, char *data_n);
void add_func(stack_t **stack, unsigned int line_number, char *data_n);
void nop_func(stack_t **stack, unsigned int line_number, char *data_n);
void sub_func(stack_t **stack, unsigned int line_number, char *data_n);
void div_func(stack_t **stack, unsigned int line_number, char *data_n);
void mul_func(stack_t **stack, unsigned int line_number, char *data_n);
void mod_func(stack_t **stack, unsigned int line_number, char *data_n);
void pstr_func(stack_t **stack, unsigned int line_number, char *data_n);
void pchar_func(stack_t **stack, unsigned int line_number, char *data_n);
void rotl_func(stack_t **stack, unsigned int line_number, char *data_n);
void rotr_func(stack_t **stack, unsigned int line_number, char *data_n);
void stack_func(stack_t **stack, unsigned int line_number, char *data_n);
void queue_func(stack_t **stack, unsigned int line_number, char *data_n);

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
int str_to_int(char *input, int *res);
void free_str_arr(char **str_arr);
void free_stack(stack_t *head);
char *convert_int_to_str(int n);
int check_comment(char *str);

#endif /* MONTY_H */
