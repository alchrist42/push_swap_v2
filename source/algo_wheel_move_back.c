#include "push_swap.h"

void	move_elem_from_b(t_stack *stk)
{
	t_list	*curr;
	t_step	step;

	step.rb = 0;
	step.rrb = stk->lenb;
	stk->step.total = INT_MAX;
	curr = stk->b;
	while (curr)
	{
		step.ra = get_place_in_a(stk, curr->x);
		search_shortest_way(stk, &step);
		curr = curr->next;
		step.rb++;
		step.rrb--;
	}
	prepare_stacks(stk, stk->step);
	ft_stack_push(&stk->b, &stk->a, PA);
	stk->lena++;
	stk->lenb--;
}

int	get_place_in_a(t_stack *stk, int bx)
{
	int			i;
	int			ra;
	long long	dif;
	t_list		*curr;

	i = 0;
	ra = 0;
	dif = 0;
	curr = stk->a;
	while (curr)
	{
		if ((curr->x - bx > 0 && (curr->x - bx <= dif || dif <= 0))
			|| (dif <= 0 && curr->x - bx < dif))
		{
			ra = i;
			dif = curr->x - bx;
		}
		i++;
		curr = curr->next;
	}
	return (ra);
}

void	search_shortest_way(t_stack *stk, t_step *step)
{
	int	rr;
	int	rrr;

	step->rra = stk->lena - step->ra;
	rr = ft_maxint(step->ra, step->rb);
	rrr = ft_maxint(step->rra, step->rrb);
	if (rr < stk->step.total)
		update_short_way(stk, step, RA_RB, rr);
	if (rrr < stk->step.total)
		update_short_way(stk, step, RRA_RRB, rrr);
	if (step->ra + step->rrb < stk->step.total)
		update_short_way(stk, step, RA_RRB, step->ra + step->rrb);
	if (step->rra + step->rb < stk->step.total)
		update_short_way(stk, step, RRA_RB, step->rra + step->rb);
}

void	update_short_way(t_stack *stk, t_step *step, int mode, int total)
{
	stk->step.mode = mode;
	stk->step.total = total;
	stk->step.ra = step->ra;
	stk->step.rb = step->rb;
	stk->step.rra = step->rra;
	stk->step.rrb = step->rrb;
}

void	prepare_stacks(t_stack *stk, t_step step)
{
	while (step.mode == RA_RB && step.ra > 0 && step.rb > 0)
	{
		step.ra--;
		step.rb--;
		ft_stack_drotate(&stk->a, &stk->b);
	}
	while (step.mode == RRA_RRB && step.rra > 0 && step.rrb > 0)
	{
		step.rra--;
		step.rrb--;
		ft_stack_drev_rotate(&stk->a, &stk->b);
	}
	while ((step.mode == RA_RB || step.mode == RA_RRB) && step.ra-- > 0)
		ft_stack_rotate(&stk->a, RA);
	while ((step.mode == RRA_RRB || step.mode == RRA_RB) && step.rra-- > 0)
		ft_stack_rev_rotate(&stk->a, RRA);
	while ((step.mode == RA_RB || step.mode == RRA_RB) && step.rb-- > 0)
		ft_stack_rotate(&stk->b, RB);
	while ((step.mode == RRA_RRB || step.mode == RA_RRB) && step.rrb-- > 0)
		ft_stack_rev_rotate(&stk->b, RRB);
}
