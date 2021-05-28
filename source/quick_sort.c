#include "push_swap.h"

void	ft_lstquick_sort(t_list **lst, int n)
{
	t_list	*midle;
	int		mid;

	if (n < 2)
		return ;
	midle = *lst;
	mid = 0;
	while (mid < n / 2)
	{
		midle = midle->next;
		mid++;
	}
	ft_stack_move_to_right(lst, midle, &mid, n / 2);
	ft_stack_move_to_left(lst, midle, &mid, n - mid - 1);
	ft_lstquick_sort(lst, mid);
	ft_lstquick_sort(&midle->next, n - mid - 1);
	return ;
}

void	ft_stack_move_to_right(t_list **lst, t_list *midle, int *mid, int cnt)
{
	t_list	*curr;
	t_list	*prev;
	t_list	*next;

	curr = *lst;
	prev = curr;
	
	while (cnt--)
	{
		next = curr->next;
		if (curr->x >= midle->x)
		{
			if (prev == *lst)
			{
				ft_lstadd_front(&midle->next, ft_lstpop_find(lst, curr->x));
				prev = *lst;
			}
			else
				ft_lstadd_front(&midle->next, ft_lstpop_find(&prev, curr->x));
			(*mid)--;
		}
		else
			prev = curr;
		curr = next;
	}
}

void	ft_stack_move_to_left(t_list **lst, t_list *midle, int *mid, int cnt)
{
	t_list	*curr;
	t_list	*prev;
	t_list	*next;
	
	curr = midle->next;
	prev = midle;
	while (cnt--)
	{
		next = curr->next;
		if (curr->x < midle->x)
		{
			ft_lstadd_front(lst, ft_lstpop_find(&prev, curr->x));
			(*mid)++;
		}
		else
			prev = curr;
		curr = next;
	}
}