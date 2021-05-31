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
	// ft_alg1_rec(stk, "B", cnt);
	// ft_alg1_sliv(stk, stk->lena, cnt);

}

// sort by 2 and merge
void	alg2(t_stack *stk, int len)
{
	t_list  *elem;
	t_list	*next;
	int	i;

	i = 1;
	elem = stk->a;
	while (i < len)
	{
		next = elem->next->next;
		if (elem->x > elem->next->x)
			ft_stack_swap(&stk->a, SA);
		ft_stack_rotate(&stk->a, RA); // todo push half to B
		ft_stack_rotate(&stk->a, RA);
		elem = next;
		i += 2;
	}
	if (len % 2)
		ft_stack_rotate(&stk->a, RA);
	i = 0;
	while (i++ < alg2_to_push(len, 2))
		ft_stack_push(&stk->a, &stk->b, PB);
	if (len % 2)
		ft_stack_rev_rotate(&stk->a, RA);
	
	alg2_rec(stk, len, 2);

}

int	alg2_to_push(int len, int gs)
{
	printf("npush len=%d, gs=%d\n", len, gs);
	return ((len / (2 * gs)) * gs + (len % gs) * ((len / gs) % 2));
}

void	alg2_rec(t_stack *stk, int len, int group_size)
{
	// t_list  *elem;
	// t_list	*next;
	// int		total_group;
	// int		current_group;
	int	a_gr;
	int	b_gr;
	int	full_grooups;

	if (!stk->b)
		return ;
	
	printf("___\n");
	print_stack(stk->a, "A: ");
	print_stack(stk->b, "B: ");

	full_grooups = len / (group_size * 2) + 1;
	while (full_grooups--)
	{
		// break ;
		
		print_stack(stk->a, "A:() ");
		print_stack(stk->b, "B:() ");
		a_gr = group_size;
		b_gr = group_size;
		if (!full_grooups)
		{
			// a_gr = (len % (group_size );
			b_gr = (len % group_size) * ((len / group_size) % 2);
		}
		printf("len=%d, gs=%d, ag=%d, bg=%d\n", len, group_size, a_gr, b_gr);
		while (a_gr || b_gr)
		{
			if (a_gr && (!stk->b || !b_gr || ft_lstlast(stk->a)->x > stk->b->x))
			{
				ft_stack_rev_rotate(&stk->a, RA);
				a_gr--;
			}
			else
			{
				ft_stack_push(&stk->b, &stk->a, PA);
				b_gr--;
			}
			
		}
		
	}
	int i;
	i = 0;
	while (i++ < alg2_to_push(len, group_size * 2))
		ft_stack_push(&stk->a, &stk->b, PB);
	alg2_rec(stk, len, group_size * 2);
}