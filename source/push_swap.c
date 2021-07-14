#include "push_swap.h"

/*
**	@brief	commands for test:
**	ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`;
**	./push_swap $ARG | ./checker $ARG
**	@param	argc		
**	@param	argv		
**	@return	int	
*/
int	main(int argc, char **argv)
{
	t_stack	stk;

	stk.a = NULL;
	stk.b = NULL;
	parcing_args(argc, argv, &stk);
	if (!ft_lstsort(stk.a, 1))
		return (0);
	if (stk.lena <= 5)
		alg2_small(&stk, stk.lena);
	else if (stk.lena < 2000)
		alg_wheel(&stk, stk.lena);
	else
		alg2(&stk, stk.lena);
	return (0);
}
