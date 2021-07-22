#include "push_swap.h"

/*
**	@brief	raises error message and exit from program
**	
**	@param	s	pointer to string with error message
*/
void	ft_raise_error(char *s)
{
	ft_putstr_fd("Error\n", 2);
	if (DEBUG && s)
		ft_putstr_fd(s, 2);
	exit (1);
}

/*
**	@brief	prints all element of list one line
**	
**	@param	lst		pointer to list
**	@param	s		message string
*/
void	print_stack(t_list *lst, char *s)
{
	if (DEBUG)
		ft_putstr_fd(s, 1);
	while (lst)
	{
		ft_putnbr_fd(lst->x, 1);
		if (lst->next)
			ft_putstr_fd(" ", 1);
		lst = lst->next;
	}
	ft_putstr_fd("\n", 1);
}

int	ft_maxint(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
