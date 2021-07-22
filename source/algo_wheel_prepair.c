#include "push_swap.h"

/*
**		@brief		search for three quartiles
*/
void	find_quartiles(t_stack *stk, int len)
{
	int		i;
	t_list	*elem;

	i = 0;
	elem = stk->sorted;
	while (elem)
	{
		if (i == len / 4)
			stk->q1 = elem->x;
		else if (i == len / 2)
			stk->q2 = elem->x;
		else if (i == len * 3 / 4)
		{
			stk->q3 = elem->x;
			return ;
		}
		i++;
		elem = elem->next;
	}
}

/*
**		@brief	moves all elements from a to b, segregated by quartiles
*/
void	move_4block_to_b(t_stack *stk, int len)
{
	int	i;

	i = 0;
	while (i++ < len)
	{
		if (stk->a->x >= stk->q2 && stk->a->x <= stk->q3)
			ft_stack_push(&stk->a, &stk->b, PB);
		else if (stk->a->x >= stk->q1 && stk->a->x < stk->q2)
		{
			ft_stack_push(&stk->a, &stk->b, PB);
			ft_stack_rotate(&stk->b, RB);
		}
		else
			ft_stack_rotate(&stk->a, RA);
	}
	while (stk->a && stk->a->next)
	{
		ft_stack_push(&stk->a, &stk->b, PB);
		if (stk->b->x > stk->q3)
			ft_stack_rotate(&stk->b, RB);
	}
	stk->lenb = stk->lena - 1;
	stk->lena = 1;
}

/*
**		@brief	just moves all elements from a to b, exept last 3
*/
void	move_to_b(t_stack *stk, int len)
{
	int	x1;
	int	x2;
	int	x3;

	while (len > 3)
	{
		ft_stack_push(&stk->a, &stk->b, PB);
		len--;
	}
	x1 = stk->a->x;
	x2 = stk->a->next->x;
	if (len == 3)
		x3 = stk->a->next->next->x;
	if (len == 2 && (x1 > x2))
		ft_stack_swap(&stk->a, SA);
	if (len == 3 && (x1 > x2) + (x2 > x3) + (x3 > x1) == 2)
		ft_stack_swap(&stk->a, SA);
	stk->lenb = stk->lena - len;
	stk->lena = len;
}
