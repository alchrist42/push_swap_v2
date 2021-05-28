#include "push_swap.h"

void	alg1(t_stack *stk)
{
	t_list  *elem;
	t_list	*next;
    int     cnt;

	cnt = 0;
    elem = stk->a;
    while (elem->next)
    {
        next = elem->next;
		if (elem->x == stk->maxa)
			ft_stack_rotate(&stk->a, RA);
		else if (elem->x > next->x)
		{
			cnt++;
			stk->lena--;
			ft_stack_push(&stk->a, &stk->b, PB);
		}
		elem = next;
    }
	ft_stack_rev_rotate(&stk->a, RRA);
	ft_alg1_rec(stk, "B", cnt);
	ft_alg1_sliv(stk, stk->lena, cnt);

}