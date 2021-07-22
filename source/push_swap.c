#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stk;

	stk.a = NULL;
	stk.b = NULL;
	stk.sorted = NULL;
	parcing_args(argc, argv, &stk);
	if (!ft_lstsort(stk.a, 1))
		return (0);
	if (stk.lena < 2121)
		alg_wheel(&stk, stk.lena);
	else
		alg2_merge(&stk, stk.lena);
	ft_lstclear(&stk.a);
	ft_lstclear(&stk.sorted);
	return (0);
}
