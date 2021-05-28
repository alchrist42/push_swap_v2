#include "push_swap.h"

void	parcing_args(int argc, char **argv, t_stack *stk)
{
	long long	x;
	int 		i;
	
	i = argc;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		i = ft_split_len(argv);
	}
	stk->lena = i - (argc != 2);
	stk->maxa = INT_MIN;
	while(--i + (argc == 2))
	{
		if (ft_atoi_long(argv[i], &x) || ft_lstfind(stk->a, x))
			ft_raise_error("Not integer in args or double\n");
		ft_lstadd_front(&stk->a, ft_lstnew(x));
		if (stk->a->x > stk->maxa)
			stk->maxa = stk->a->x;
	}
	if (argc == 2)
		ft_split_free(argv);
}