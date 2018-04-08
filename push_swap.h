/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meyami <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 17:55:50 by meyami            #+#    #+#             */
/*   Updated: 2018/04/06 17:56:10 by meyami           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/includes/libft.h"
# include <stdlib.h>

typedef struct	s_instruct
{
	char				*instruction;
	struct s_instruct	*next;
}				t_instruct;

typedef struct	s_stack
{
	int			*nb;
	int			size;
	int			memory;
	t_instruct	*instructions;
}				t_stack;

void			print_stacks(t_stack *a, t_stack *b);

void			error_message(void);
void			error_message_free_args(char **tab);
void			error_message_free_stacks(t_stack *a, t_stack *b);

void			args_check_single(t_stack *a, t_stack *b, char **argv);
void			args_check_multi(t_stack *a, t_stack *b, char **argv);
void			args_free(char **args);

int				stack_pop(t_stack *stack);
void			stack_push(t_stack *stack, int n);
int				stack_peek(t_stack *stack);

int				content_contains(t_stack *stack, int n);
int				content_contains_higher(t_stack *stack, int n);
int				content_contains_lower(t_stack *stack, int n);
int				content_is_ordered(t_stack *stack);
int				content_is_inverse_ordered(t_stack *stack);

void			instructions_read(t_stack *a, t_stack *b, int verbose);
void			instructions_exec(t_stack *a, t_stack *b, char *new_instruct);
void			instructions_enqueue(t_stack *a, t_stack *b, char *new_instruct);
void			instructions_print(t_instruct *instructions);

void			clean_instructions(t_instruct *instructions);
int				clean_wide_enough(t_instruct *instructions);
int				clean_redundancy(char *s1, char *s2);
char			*clean_mixable(char *s1, char *s2);

void			op_swap(t_stack *a, t_stack *b, char option);
void			op_push(t_stack *a, t_stack *b, char option);
void			op_rotate(t_stack *a, t_stack *b, char option);
void			op_reverse_rotate(t_stack *a, t_stack *b, char option);

void		sort_three_or_five(t_stack *a, t_stack *b, int number);
void			sort_a(t_stack *a, t_stack *b, int elements, int reorder);
void			sort_b(t_stack *a, t_stack *b, int elements);
int				sort_less_than_two_elements_a(t_stack *a, t_stack *b,
												int elements);
int				sort_less_than_two_elements_b(t_stack *a, t_stack *b,
												int elements);

int				subset_median(int *set, int len, int rank);
int				subset_ordered(t_stack *stack, int elements);
int				subset_inverse_ordered(t_stack *stack, int elements);
void			subset_flush_a(t_stack *a, t_stack *b, int elements);
void			subset_flush_b(t_stack *a, t_stack *b, int elements);

#endif
