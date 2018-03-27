#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/includes/libft.h"
# include <stdlib.h>

typedef struct	s_num
{
	int *numbers;
	int nb_args;
}				t_num;

void	error_message(void);
void	error_message_free_args(char **tab);

void	args_check_single(t_num *numbers, char **argv);
void	args_check_multi(t_num *numbers, char **argv);

void	numbers_init(t_num *numbers);
void	numbers_swap(t_num *numbers, int i, int j);
int		numbers_are_sorted(t_num *numbers);

#endif
