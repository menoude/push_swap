#include "push_swap.h"

void	op_swap(t_stack *a, t_stack *b, char option)
{
	int tmp;

	if (option == 'a')
	{
		tmp = a->nb[a->size - 1];
		a->nb[a->size - 1] = a->nb[a->size - 2];
		a->nb[a->size - 2] = tmp;
	}
	else if (option == 'b')
	{
		tmp = b->nb[b->size - 1];
		b->nb[b->size - 1] = b->nb[b->size - 2];
		b->nb[b->size - 2] = tmp;
	}
}

void	op_push(t_stack *a, t_stack *b, char option)
{
	if (option == 'a')
		stack_push(a, stack_pop(b));
	else if (option == 'b')
		stack_push(b, stack_pop(a));
}

void	op_rotate(t_stack *a, t_stack *b, char option)
{
	int tmp;
	int i;

	i = 0;
	if (option == 'a')
	{
		tmp = a->nb[a->size - 1];
		while (i + 1 < a->size)
		{
			a->nb[i + 1] = a->nb[i];
			i++;
		}
		a->nb[0] = tmp;
	}
	else if (option == 'b')
	{
		tmp = b->nb[b->size - 1];
		while (i + 1 < b->size)
		{
			b->nb[i + 1] = b->nb[i];
			i++;
		}
		b->nb[0] = tmp;
	}
}

void	op_reverse_rotate(t_stack *a, t_stack *b, char option)
{
	int tmp;
	int i;

	i = 1;
	if (option == 'a')
	{
		tmp = a->nb[0];
		while (i < a->size)
		{
			a->nb[i - 1] = a->nb[i];
			i++;
		}
		a->nb[a->size - 1] = tmp;
	}
	else if (option == 'b')
	{
		tmp = b->nb[0];
		while (i < b->size)
		{
			b->nb[i - 1] = b->nb[i];
			i++;
		}
		b->nb[b->size - 1] = tmp;
	}
}
