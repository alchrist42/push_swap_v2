#include "checker.h"

void	parcing_args(int argc, char **argv, t_stack *stk)
{
	long long	x;
	int			i;

	i = argc;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		i = ft_split_len(argv);
	}
	stk->lena = i - (argc != 2);
	stk->maxa = INT_MIN;
	while (--i + (argc == 2))
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

/*
**	@brief	parsing lines from standart input
**	
**	@param	stk		pointer to stack
*/
void	parcing_instructions(t_stack *stk)
{
	char	*line;
	int		res;

	res = 1;
	while (res)
	{
		res = get_next_line(0, &line);
		if (res < 0 || (res == 0 && ft_strlen(line)))
			ft_raise_error("gnl exit incorrect\n");
		if (res)
			switch_instruction(stk, line);
		free(line);
	}
}

/*
**	@brief	switches and executes the instruction
**	
**	@param	stk		pointer to stack
**	@param	line	string instruction
*/
void	switch_instruction(t_stack *stk, char *line)
{
	if (!ft_strncmp("sa", line, 3))
		ft_stack_swap(&stk->a, "swap a");
	else if (!ft_strncmp("sb", line, 3))
		ft_stack_swap(&stk->b, "swap b");
	else if (!ft_strncmp("ss", line, 3))
		ft_stack_dswap(&stk->a, &stk->b);
	else if (!ft_strncmp("ra", line, 3))
		ft_stack_rotate(&stk->a, "rotate a");
	else if (!ft_strncmp("rb", line, 3))
		ft_stack_rotate(&stk->b, "rotate b");
	else if (!ft_strncmp("rr", line, 3))
		ft_stack_drotate(&stk->a, &stk->b);
	else if (!ft_strncmp("rra", line, 4))
		ft_stack_rev_rotate(&stk->a, "rev rotate a");
	else if (!ft_strncmp("rrb", line, 4))
		ft_stack_rev_rotate(&stk->b, "rev rotate b");
	else if (!ft_strncmp("rrr", line, 4))
		ft_stack_drev_rotate(&stk->a, &stk->b);
	else if (!ft_strncmp("pa", line, 3))
		ft_stack_push(&stk->b, &stk->a, "push from b to a");
	else if (!ft_strncmp("pb", line, 3))
		ft_stack_push(&stk->a, &stk->b, "push from a to b");
	else
		ft_raise_error(line);
}
