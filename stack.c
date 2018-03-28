#include "push_swap.h"

int		stack_pop(t_stack *stack)
{
	int nb;

	nb = stack->nb[stack->size - 1];
	stack->size--;
	return (nb);
}

void	stack_push(t_stack *stack, int n)
{
	stack->nb[stack->size] = n;
	stack->size++;
}

int		stack_peek(t_stack *stack)
{
	return (stack->nb[stack->size - 1]);
}

int		stack_contains(t_stack *stack, int n)
{
	int i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->nb[i] == n)
			return (1);
		i++;
	}
	return (0);
}

int		stack_is_ordered(t_stack *stack)
{
	int i;

	i = 0;
	while (i + 1 < stack->size)
	{
		if (stack->nb[i] > stack->nb[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int		stack_init(t_stack *stack, int size)
{
	if (!(stack->nb = ft_memalloc(sizeof(int) * size)))
		return(0);
	stack->size = size;
	return (1);
}
