#include "push_swap.h"

/*
**		@brief	The main idea - we are looking for the element
**				with the shortest path in the stack b 
**				to the correct place in the stack a.
**				Additionally, divides the big stack into 4 subgroups.
*/
void	alg_wheel(t_stack *stk, int len)
{
	if (len < 42)
		move_to_b(stk, len);
	else
	{
		ft_lstquick_sort(&stk->sorted, len);
		find_quartiles(stk, len);
		move_4block_to_b(stk, len);
	}
	while (stk->b)
		move_elem_from_b(stk);
	shift_to_begin(stk);
}

/*
**		@brief	shifts the begin of sorted stack to the smallest element
*/
void	shift_to_begin(t_stack *stk)
{
	int		ra;
	t_list	*curr;

	ra = 1;
	curr = stk->a;
	while (curr->next)
	{
		if (curr->x > curr->next->x)
			break ;
		curr = curr->next;
		ra++;
	}
	if (ra <= stk->lena / 2)
		while (ra--)
			ft_stack_rotate(&stk->a, RA);
	else
		while (ra++ < stk->lena)
			ft_stack_rev_rotate(&stk->a, RRA);
}
