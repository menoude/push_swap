#include "push_swap.h"

static void instructions_check(t_stack *a, t_stack *b, char *new_instruct)
{
	if (ft_strequ(new_instruct, "sa") || ft_strequ(new_instruct, "sb")
		|| ft_strequ(new_instruct, "sb"))
		op_swap(a, b, new_instruct[1]);
	else if (ft_strequ(new_instruct, "pa") || ft_strequ(new_instruct, "pb"))
		op_push(a, b, new_instruct[1]);
	else if (ft_strequ(new_instruct, "ra") || ft_strequ(new_instruct, "rb")
			|| ft_strequ(new_instruct, "rr"))
		op_rotate(a, b, new_instruct[1]);
	else if (ft_strequ(new_instruct, "rra") || ft_strequ(new_instruct, "rrb")
			|| ft_strequ(new_instruct, "rrr"))
		op_reverse_rotate(a, b, new_instruct[2]);
	else
		error_message_free_stacks(a, b);
}

void	instructions_read(t_stack *a, t_stack *b)
{
	char *instruct;

	instruct = 0;
	while (get_next_line(0, &instruct) > 0)
	{
		instructions_check(a, b, instruct);
		print_stacks(a, b);
		free(instruct);
	}
}
