#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/includes/libft.h"
# include <stdlib.h>

typedef struct	s_stack
{
	int *nb;
	int size;
	int memory;
}				t_stack;

///////////////////////////////////

void print_stacks(t_stack *a, t_stack *b);
void	print_set(int *set, char *name, int size);
int counter;
////////////////////////////////////

void	error_message(void);
void	error_message_free_args(char **tab);
void	error_message_free_stacks(t_stack *a, t_stack *b);

void	args_check_single(t_stack *a, t_stack *b, char **argv);
void	args_check_multi(t_stack *a, t_stack *b, char **argv);
void	args_free(char **args);

int		stack_pop(t_stack *stack);
void	stack_push(t_stack *stack, int n);
int		stack_peek(t_stack *stack);
int		stack_contains(t_stack *stack, int n);
int		stack_is_ordered(t_stack *stack);
int		stack_init(t_stack *stack);

void	instructions_read(t_stack *a, t_stack *b);
void	instructions_exec(t_stack *a, t_stack *b, char *new_instruct, int print);

void	op_swap(t_stack *a, t_stack *b, char option);
void	op_push(t_stack *a, t_stack *b, char option);
void	op_rotate(t_stack *a, t_stack *b, char option);
void	op_reverse_rotate(t_stack *a, t_stack *b, char option);

void	sort(t_stack *a, t_stack *b, int rank);

#endif
