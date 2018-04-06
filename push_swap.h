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

typedef struct	s_instruct
{
	char							*instruction;
	struct s_instruct	*next;
}								t_instruct;

// Gerer le free des listes si jamais il y a un soucis dans un malloc !!
///////////////////////////////////

void print_stacks(t_stack *a, t_stack *b);
void	print_set(int *set, char *name, int size);
int counter;
int counter_pa;
int counter_pb;
int counter_sa;
int counter_sb;
int counter_ra;
int counter_rb;
int counter_rra;
int counter_rrb;
void print_subset_instructions(int transferts);

////////////////////////////////////

void	error_message(void);
void	error_message_free_args(char **tab);
void	error_message_free_stacks(t_stack *a, t_stack *b);

void			args_check_single(t_stack *a, t_stack *b, char **argv);
void			args_check_multi(t_stack *a, t_stack *b, char **argv);
void	args_free(char **args);

int		stack_pop(t_stack *stack);
void	stack_push(t_stack *stack, int n);
int		stack_peek(t_stack *stack);
int		stack_contains(t_stack *stack, int n);
int		stack_contains_higher(t_stack *stack, int n);
int		stack_contains_lower(t_stack *stack, int n);
int		stack_is_ordered(t_stack *stack);
int		stack_is_inverse_ordered(t_stack *stack);
int		stack_init(t_stack *stack);
void	stack_raise_value(t_stack *a, t_stack *b, t_instruct *instructions, int median, char a_or_b);

void	instructions_read(t_stack *a, t_stack *b);
void	instructions_exec(t_stack *a, t_stack *b, t_instruct **lst, char *new_instruct);
void	instructions_print(t_instruct *lst);
void	instructions_enqueue(t_stack *a, t_stack *b, t_instruct **instructions, char *new_instruct);


void	op_swap(t_stack *a, t_stack *b, char option);
void	op_push(t_stack *a, t_stack *b, char option);
void	op_rotate(t_stack *a, t_stack *b, char option);
void	op_reverse_rotate(t_stack *a, t_stack *b, char option);

void		sort_a(t_stack *a, t_stack *b, int elements, t_instruct **instructions);
void		sort_b(t_stack *a, t_stack *b, int elements, t_instruct **instructions);

int	subset_median_value(int *set, int len, int rank);
int		subset_ordered(t_stack *stack, int elements);
int		subset_inverse_ordered(t_stack *stack, int elements);
void subset_flush_a(t_stack *a, t_stack *b, t_instruct *instructions, int elements);
void subset_flush_b(t_stack *a, t_stack *b, t_instruct *instructions, int elements);


#endif
