#include "push_swap.h"

void	checker_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

void	checker_error_free(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	write(2, "Error\n", 6);
	exit(0);
}

void	checker_valid_arg(char **argv)
{
	char		**tab;
	int			k;
	int			i;
	long int	n;

	if (!(tab = ft_strsplit(argv[1], ' ')))
		checker_error();
	k = 0;
	while (tab[k])
	{
		i = 0;
		while (tab[k][i])
		{
			if (!ft_isdigit(tab[k][i]) && !(i == 0 && tab[k][i] == '-'
											&& tab[k][i + 1]))
				checker_error_free(tab);
			i++;
		}
		n = ft_atoi_long(tab[k]);
		if ((n > 0 && n > 2147483647) || (n < 0 && n < -2147483648))
			checker_error_free(tab);
		k++;
	}
}

void	checker_valid_args(int argc, char **argv)
{
	int			k;
	int			i;
	long int	n;

	k = 1;
	while (k < argc)
	{
		if (!argv[k])
			checker_error();
		i = 0;
		while (argv[k][i])
		{
			if (!ft_isdigit(argv[k][i]) && !(i == 0 && argv[k][i] == '-'
											&& argv[k][i + 1]))
				checker_error();
			i++;
		}
		n = ft_atoi_long(argv[k]);
		if ((n > 0 && n > 2147483647) || (n < 0 && n < -2147483648))
			checker_error();
		k++;
	}
}

int		main(int argc, char **argv)
{
	if (argc < 2)
		checker_error();
	else if (argc == 2)
		checker_valid_arg(argv);
	else if (argc > 2)
		checker_valid_args(argc, argv);
}
