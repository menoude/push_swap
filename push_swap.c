#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack a;
    t_stack b;

	if (argc < 2)
		error_message();
	else if (argc == 2)
		args_check_single(&a, &b, argv);
	else if (argc > 2)
		args_check_multi(&a, &b, argv);
	print_stacks(&a, &b);
  // counter = 0;
	sort(&a, &b, 0, a->size);
  // ft_printf("%d instructions\n", counter);
	return (0);
}
