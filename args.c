#include "push_swap.h"

static int args_no_duplicates(t_num *numbers, int nb_saved, int next_nb)
{
	int i;

	i = 0;
	while (i < nb_saved)
	{
		if (numbers->numbers[i] == next_nb)
			return (0);
		i++;
	}
	return (1);
}

static void args_finalize(t_num *numbers, char **args, int to_free)
{
	int i;
	int next_nb;

	numbers->numbers = ft_memalloc(sizeof(int) * numbers->nb_args);
	i = -1;
	while (++i < numbers->nb_args)
	{
		next_nb = ft_atoi(args[i]);
		if (!args_no_duplicates(numbers, i, next_nb))
		{
			free(numbers->numbers);
			if (to_free)
				error_message_free_args(args);
			else
				error_message();
		}
		numbers->numbers[i] = next_nb;
	}
	if (to_free)
	{
		i = -1;
		while (args[++i])
			free(args[i]);
		free(args);
	}
}

void	args_check_single(t_num *numbers, char **argv)
{
	char		**tab;
	int			k;
	int			i;
	long int	n;

	if (!(tab = ft_strsplit(argv[1], ' ')))
		error_message();
	k = 0;
	while (tab[k])
	{
		i = 0;
		while (tab[k][i])
		{
			if (!ft_isdigit(tab[k][i]) && !(i == 0 && tab[k][i] == '-'
											&& tab[k][i + 1]))
				error_message_free_args(tab);
			i++;
		}
		n = ft_atoi_long(tab[k]);
		if ((n > 0 && n > 2147483647) || (n < 0 && n < -2147483648))
			error_message_free_args(tab);
		k++;
		numbers->nb_args++;
	}
	args_finalize(numbers, tab, 1);
}

void	args_check_multi(t_num *numbers, char **argv)
{
	int			k;
	int			i;
	long int	n;

	k = 1;
	while (argv[k])
	{
		i = 0;
		while (argv[k][i])
		{
			if (!ft_isdigit(argv[k][i]) && !(i == 0 && argv[k][i] == '-'
											&& argv[k][i + 1]))
				error_message();
			i++;
		}
		n = ft_atoi_long(argv[k]);
		if ((n > 0 && n > 2147483647) || (n < 0 && n < -2147483648))
			error_message();
		k++;
		numbers->nb_args++;
	}
	args_finalize(numbers, argv + 1, 0);
}
