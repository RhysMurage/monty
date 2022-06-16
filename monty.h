#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>


/* fileptr points to file with byte code*/

extern FILE *fileptr;
FILE *fileptr;

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

void pall(stack_t **stack, unsigned int line_number);

void push(stack_t **stack, unsigned int line_number);

char **readlines(FILE *filepointer);

char **tokenizer(char *lines);

char *get_op(char **tokens);

#endif /* _MONTY_H_ */
