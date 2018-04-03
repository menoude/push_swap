#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack a;
	t_stack b;
	t_stack medians;

	if (argc < 2)
	error_message();
	else if (argc == 2)
	args_check_single(&a, &b, argv, &medians);
	else if (argc > 2)
	args_check_multi(&a, &b, argv, &medians);
	print_stacks(&a, &b);
	counter = 0;
	sort_a(&a, &b, a.size);
	ft_printf("%d instructions\n", counter);
	free(a.nb);
	free(b.nb);
	free(medians.nb);
	return (0);
}
