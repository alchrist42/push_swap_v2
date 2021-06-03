#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "libft.h"
# include "get_next_line.h"

# define DEBUG 0
# define OUT 0

typedef struct s_stack
{
	t_list	*a;
	t_list	*b;
	int		lena;
	int		lenb;
	int		maxa;
}	t_stack;

//checker
int		main(int argc, char **argv);

//parcing
void	parcing_args(int n, char **argv, t_stack *stk);
void	parcing_instructions(t_stack *stk);
void	switch_instruction(t_stack *stk, char *line);

// raise_error
void	ft_raise_error(char *s);

// stack_operators
void	ft_stack_swap(t_list **lst, char *s);
void	ft_stack_dswap(t_list **lst1, t_list **lst2);
void	ft_stack_push(t_list **lst1, t_list **lst2, char *s);

// lst_operators2
void	ft_stack_rotate(t_list **lst, char *s);
void	ft_stack_drotate(t_list **lst1, t_list **lst2);
void	ft_stack_rev_rotate(t_list **lst, char *s);
void	ft_stack_drev_rotate(t_list **lst1, t_list **lst2);

#endif