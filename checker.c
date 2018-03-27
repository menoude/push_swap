#include "push_swap.h"

void	error_message(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

void	error_message_free_args(char **tab)
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

int		main(int argc, char **argv)
{
	t_num	numbers;
	char		*line;

	numbers_init(&numbers);
	if (argc < 2)
		error_message();
	else if (argc == 2)
		args_check_single(&numbers, argv);
	else if (argc > 2)
		args_check_multi(&numbers, argv);
	while (get_next_line(0, &line) > 0)
	{
		// if (!instruction_check())
			// error_message_free_;
		free(line);
	}

}
