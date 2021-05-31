#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_stack	stk;

	stk.a = NULL;
	stk.b = NULL;
	parcing_args(argc, argv, &stk);

	
	// print_stack(stk.a, "A: ");
	// print_stack(stk.b, "B: ");
	// ft_stack_swap(&stk.a, "sa");
	// ft_stack_push(&stk.a, &stk.b, "pb");
	// ft_stack_push(&stk.a, &stk.b, "pb");
	// ft_stack_push(&stk.a, &stk.b, "pb");
	// ft_stack_rotate(&stk.a, "ra");
	// ft_stack_rotate(&stk.b, "rb");
	// // ft_stack_drev_rotate(&stk.a, &stk.b);
	// ft_stack_rev_rotate(&stk.a, "rra");
	// ft_stack_rev_rotate(&stk.b, "rrb");
	// // ft_stack_drev_rotate(&stk.a, &stk.b);
	// ft_stack_swap(&stk.a, "sa");
	// ft_stack_push(&stk.b, &stk.a, "pa");
	// ft_stack_push(&stk.b, &stk.a, "pa");
	// ft_stack_push(&stk.b, &stk.a, "pa");


	

	
	// ft_lstquick_sort(&stk.a, stk.lena);
	alg2(&stk, stk.lena);
	print_stack(stk.a, "A: ");
	print_stack(stk.b, "B: ");
	if (ft_lstsort(stk.a, 1))
		ft_putstr_fd("KO\n", 1);
	else
		ft_putstr_fd("OK\n", 1);

	
}

// void	ft_algo1(stack_t *sta, stack_t *stb)
// {
	
// }