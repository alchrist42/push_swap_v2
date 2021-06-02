#include "push_swap.h"

void	alg1(t_stack *stk, int len)
{
	t_list  *elem;
	t_list	*next;
    int     cnt;

	cnt = 0;
    elem = stk->a;
    while (elem->next && len--)
    {
        next = elem->next;
		if (elem->x > next->x)
		{
			cnt++;
			stk->lena--;
			ft_stack_push(&stk->a, &stk->b, PB);
		}
		else
			ft_stack_rotate(&stk->a, RA);
		elem = next;
    }
	ft_stack_rev_rotate(&stk->a, RRA);
}

// sort by 2 and merge
void	alg2(t_stack *stk, int len)
{
	int	i;

	i = (len % 4 == 3);
	if (i)
		ft_stack_push(&stk->a, &stk->b, PB);
	while (i < len)
	{
		// printf("len = %d, i = %d\n",len,  i);
		if (len - i >= 4)
		{
			ft_stack_push(&stk->a, &stk->b, PB);
			ft_stack_push(&stk->a, &stk->b, PB);
			if (stk->b->x < stk->b->next->x && stk->a->x > stk->a->next->x)
				ft_stack_dswap(&stk->a, &stk->b);
			else if (stk->b->x < stk->b->next->x)
				ft_stack_swap(&stk->b, SB);
			i += 2;
		}
		if (len - i > 1 && stk->a->x > stk->a->next->x)
			ft_stack_swap(&stk->a, SA);
		if (len - i > 2)
		{
			ft_stack_rotate(&stk->a, RA);
			ft_stack_rotate(&stk->a, RA);
		}
		// else if (len - i == 1 && len > 4)
		// 	ft_stack_rotate(&stk->a, RA);
		i += 2;	
	}
			
	alg2_rec(stk, stk->lena, 2);

}

int	alg2_to_push(int len, int gs)
{
	// printf("npush len=%d, gs=%d\n", len, gs);
	return ((len / (2 * gs)) * gs + (len % gs) * ((len / gs) % 2));
}

void	alg2_rec(t_stack *stk, int len, int group_size)
{
	int	i;
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
		{
			if (a_gr && (!stk->b || !b_gr || ft_lstlast(stk->a)->x > stk->b->x))
			{
				ft_stack_rev_rotate(&stk->a, RRA);
				a_gr--;
			}
			else
			{
				ft_stack_push(&stk->b, &stk->a, PA);
				b_gr--;
			}
		}
	}
	
	
	i = 0;
	while (i++ < len % (group_size * 2) && !(len / (group_size * 2) % 2) && group_size * 2 < len)
		ft_stack_rotate(&stk->a, RA);
	i = 0;
	while (i++ < alg2_to_push(len, group_size * 2))
		ft_stack_push(&stk->a, &stk->b, PB);
	i = 0;
	while (i++ < len % (group_size * 2) && !(len / (group_size * 2) % 2) && group_size * 2 < len)
		ft_stack_rev_rotate(&stk->a, RRA);
	alg2_rec(stk, len, group_size * 2);
}

void	alg_small(t_stack *stk, int len)
{
	if (len == 5)
		ft_stack_push(&stk->a, &stk->b, PB);
	if (len >= 4)
		ft_stack_push(&stk->a, &stk->b, PB);
	if (len == 5 && stk->b->x < stk->b->next->x)
		ft_stack_swap(&stk->b, SB);
	if (len >= 3)
	{
		if (stk->a->next->x > stk->a->x && stk->a->next->x > stk->a->next->next->x)
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
	while (len) 
	{
		if (ft_lstsize(stk->b) < len && (!stk->b || ft_lstlast(stk->a)->x > stk->b->x))
			ft_stack_rev_rotate(&stk->a, RRA);
		else
			ft_stack_push(&stk->b, &stk->a, PA);
		len--;
	}
}