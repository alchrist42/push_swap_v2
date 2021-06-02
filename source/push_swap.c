#include "push_swap.h"

// ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker_m $ARG
// ARG=`ruby -e "puts (1..100).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l
// python3 pyviz.py `ruby -e "puts (1..20).to_a.shuffle.join(' ')"`

int		main(int argc, char **argv)
{
	t_stack	stk;

	stk.a = NULL;
	stk.b = NULL;
	parcing_args(argc, argv, &stk);
	if (!ft_lstsort(stk.a, 1))
		return (0);
	if (stk.lena <= 5)
		alg_small(&stk, stk.lena);
	else
		alg2(&stk, stk.lena);

	// if (ft_lstsort(stk.a, 1))
	// 	ft_putstr_fd("KO\n", 1);
	// else
	// 	ft_putstr_fd("OK\n", 1);

	return (0);
}
