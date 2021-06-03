#include "checker.h"

/*
**	@brief	swaps first two elements in the list
**	
**	@param	lst		pointer to list
**	@param	s		message string
*/
void	ft_stack_swap(t_list **lst, char *s)
{
	int	temp;

	if (*lst && (*lst)->next)
	{
		temp = (*lst)->next->x;
		(*lst)->next->x = (*lst)->x;
		(*lst)->x = temp;
		if (s && OUT)
			ft_putendl_fd(s, 1);
	}
}

/*
**	@brief		swaps first two elements in the both lists
**	
**	@param	lst1	pointer to list
**	@param	lst2	pointer to list
*/
void	ft_stack_dswap(t_list **lst1, t_list **lst2)
{
	ft_stack_swap(lst1, NULL);
	ft_stack_swap(lst2, NULL);
	if (OUT)
		ft_putendl_fd("ss", 1);
}

/*
**	@brief	moves first element from the list1 to the top of the list2
**	
**	@param	lst1	pointer to list
**	@param	lst2	pointer to list
**	@param	s		message string
*/
void	ft_stack_push(t_list **lst1, t_list **lst2, char *s)
{
	if (*lst1)
		ft_lstadd_front(lst2, ft_lstpop(lst1, true));
	if (OUT)
		ft_putendl_fd(s, 1);
}
