#include "checker.h"

/*
**	@brief	puhs first element to the end of stack
**	
**	@param	lst		pointer to stack
**	@param	s		message
*/
void	ft_stack_rotate(t_list **lst, char *s)
{
	if (*lst)
		ft_lstadd_back(lst, ft_lstpop(lst, true));
	if (s && OUT)
		ft_putendl_fd(s, 1);
}

/*
**	@brief	push first elements to the end for both stack
**	
**	@param	lst1		DOC
**	@param	lst2		DOC
*/
void	ft_stack_drotate(t_list **lst1, t_list **lst2)
{
	ft_stack_rotate(lst1, NULL);
	ft_stack_rotate(lst2, NULL);
	if (OUT)
		ft_putendl_fd("rr", 1);
}

/*
**	@brief	move last element to the top of the stack
**	
**	@param	lst		pointer to stack
**	@param	s		message
*/
void	ft_stack_rev_rotate(t_list **lst, char *s)
{
	if (*lst)
		ft_lstadd_front(lst, ft_lstpop(lst, false));
	if (s && OUT)
		ft_putendl_fd(s, 1);
}

/*
**	@brief	push last elements to the top of both stack
**	
**	@param	lst1		DOC
**	@param	lst2		DOC
*/
void	ft_stack_drev_rotate(t_list **lst1, t_list **lst2)
{
	ft_stack_rev_rotate(lst1, NULL);
	ft_stack_rev_rotate(lst2, NULL);
	if (OUT)
		ft_putendl_fd("rrr", 1);
}
