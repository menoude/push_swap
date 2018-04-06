#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack 		a;
	t_stack 		b;
	t_instruct	*instructions;

	if (argc < 2)
	error_message();
	else if (argc == 2)
	args_check_single(&a, &b, argv);
	else if (argc > 2)
	args_check_multi(&a, &b, argv);
	// print_stacks(&a, &b);
	counter = 0;
	instructions = 0;
	sort_a(&a, &b, a.size, &instructions);
	instructions_print(instructions);
	// print_stacks(&a, &b);
	// ft_printf("%d instructions for %d elements\n stack ordered? %s\n", counter, a.size, stack_is_inverse_ordered(&a) ? "Yes" : "No");
	// print_subset_instructions(0);
	free(a.nb);
	free(b.nb);
	return (0);
}
