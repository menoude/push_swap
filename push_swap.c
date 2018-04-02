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
  stack_sort_a(&a, &b, &medians);
  ft_printf("%d instructions\n", counter);
	return (0);
}
