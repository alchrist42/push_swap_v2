#include "checker.h"

/*
**	@brief	commands for test:
**	ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`;
**	./push_swap $ARG | ./checker_mac $ARG
*/
int	main(int argc, char **argv)
{
	t_stack	stk;

	stk.a = NULL;
	stk.b = NULL;
	if (argc == 1)
		return (0);
	parcing_args(argc, argv, &stk);
	parcing_instructions(&stk);
	if (stk.b || ft_lstsort(stk.a, 1))
		ft_putstr_fd("KO\n", 1);
	else
		ft_putstr_fd("OK\n", 1);
	return (0);
}
