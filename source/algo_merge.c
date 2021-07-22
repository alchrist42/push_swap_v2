#include "push_swap.h"

void	alg2_merge(t_stack *stk, int len)
{
	if (len % 4 == 3)
		ft_stack_push(&stk->a, &stk->b, PB);
	len -= (len % 4 == 3);
	while (len)
	{
		if (len >= 4)
		{
			ft_stack_push(&stk->a, &stk->b, PB);
			ft_stack_push(&stk->a, &stk->b, PB);
			if (stk->b->x < stk->b->next->x && stk->a->x > stk->a->next->x)
				ft_stack_dswap(&stk->a, &stk->b);
			else if (stk->b->x < stk->b->next->x)
				ft_stack_swap(&stk->b, SB);
			len -= 2;
		}
		if (len > 1 && stk->a->x > stk->a->next->x)
			ft_stack_swap(&stk->a, SA);
		if (len > 2)
		{
			ft_stack_rotate(&stk->a, RA);
			ft_stack_rotate(&stk->a, RA);
		}
		len -= 2;
	}
	alg2_merge_blocks(stk, stk->lena, 2);
}

void	alg2_merge_blocks(t_stack *stk, int len, int group_size)
{
	int	a_gr;
	int	b_gr;
	int	full_grooups;

	if (group_size >= len)
		return ;
	full_grooups = len / (group_size * 2) + 1;
	while (full_grooups--)
	{
		a_gr = group_size;
		b_gr = group_size;
		if (!full_grooups)
			b_gr = (len % group_size) * ((len / group_size) % 2);
		if (!b_gr)
			a_gr = (len % (group_size * 2));
		while (a_gr || b_gr)
			if ((a_gr && (!stk->b || !b_gr
						|| ft_lstlast(stk->a)->x > stk->b->x)) && a_gr--)
				ft_stack_rev_rotate(&stk->a, RRA);
		else if (b_gr--)
			ft_stack_push(&stk->b, &stk->a, PA);
	}
	alg2_push_to_b(stk, stk->lena, group_size * 2);
}

void	alg2_push_to_b(t_stack *stk, int len, int gs)
{		
	int	i;
	int	size;

	size = (len / (2 * gs)) * gs + (len % gs) * ((len / gs) % 2);
	i = 0;
	while (i++ < len % gs && !(len / gs % 2) && gs < len)
		ft_stack_rotate(&stk->a, RA);
	i = 0;
	while (i++ < size)
		ft_stack_push(&stk->a, &stk->b, PB);
	i = 0;
	while (i++ < len % gs && !(len / gs % 2) && gs < len)
		ft_stack_rev_rotate(&stk->a, RRA);
	alg2_merge_blocks(stk, len, gs);
}

void	alg2_small(t_stack *stk, int len)
{
	if (len == 5)
		ft_stack_push(&stk->a, &stk->b, PB);
	if (len >= 4)
		ft_stack_push(&stk->a, &stk->b, PB);
	if (len == 5 && stk->b->x < stk->b->next->x)
		ft_stack_swap(&stk->b, SB);
	if (len >= 3)
	{
		if (stk->a->next->x > stk->a->x
			&& stk->a->next->x > stk->a->next->next->x)
			ft_stack_swap(&stk->a, SA);
		if (stk->a->x > stk->a->next->x && stk->a->x > stk->a->next->next->x)
			ft_stack_rotate(&stk->a, RA);
		if (stk->a->x > stk->a->next->x)
			ft_stack_swap(&stk->a, SA);
	}
	if (len == 2 && stk->a->x > stk->a->next->x)
		ft_stack_swap(&stk->a, SA);
	if (len <= 3)
		return ;
	alg2_merge_blocks(stk, len, 3);
}
