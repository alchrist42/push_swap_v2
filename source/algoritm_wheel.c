#include "push_swap.h"

// void	alg2(t_stack *stk, int len)
// {
// 	if (len % 4 == 3)
// 		ft_stack_push(&stk->a, &stk->b, PB);
// 	len -= (len % 4 == 3);
// 	while (len)
// 	{
// 		if (len >= 4)
// 		{
// 			ft_stack_push(&stk->a, &stk->b, PB);
// 			ft_stack_push(&stk->a, &stk->b, PB);
// 			if (stk->b->x < stk->b->next->x && stk->a->x > stk->a->next->x)
// 				ft_stack_dswap(&stk->a, &stk->b);
// 			else if (stk->b->x < stk->b->next->x)
// 				ft_stack_swap(&stk->b, SB);
// 			len -= 2;
// 		}
// 		if (len > 1 && stk->a->x > stk->a->next->x)
// 			ft_stack_swap(&stk->a, SA);
// 		if (len > 2)
// 		{
// 			ft_stack_rotate(&stk->a, RA);
// 			ft_stack_rotate(&stk->a, RA);
// 		}
// 		len -= 2;
// 	}
// 	alg2_merge(stk, stk->lena, 2);
// }

void	alg_wheel(t_stack *stk, int len)
{
	ft_lstquick_sort(&stk->sorted, len);
	find_quartiles(stk, len);
	move_to_b(stk, len);
	move_back_from_b(stk, len);
}

/*
**		@brief		search for three quartiles
*/
void	find_quartiles(t_stack *stk, int len)
{
	int	i;
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
void	move_to_b(t_stack *stk, int len)
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
	while (stk->a)
	{
		if (stk->a->x > stk->q3)
			ft_stack_push(&stk->a, &stk->b, PB);
		else
		{
			ft_stack_push(&stk->a, &stk->b, PB);
			ft_stack_rotate(&stk->b, RB);
		}
	}
}

void	move_back_from_b(t_stack *stk, int len)
{

}