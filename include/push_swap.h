#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>  // todo del

# include "libft.h"

# define DEBUG 1
# define OUT 1

# define RA "ra"
# define RB "rb"
# define RRA "rra"
# define RRB "rrb"
# define PA "pa"
# define PB "pb"

typedef struct s_stack
{
	t_list	*a;
	t_list	*b;
	int		lena;
	int		lenb;
	int		maxa;
}	t_stack;

// push_swap
int		main(int argc, char **argv);


//parcing
void	parcing_args(int n, char **argv, t_stack *stk);

// raise_error
void	ft_raise_error(char *s);
void	print_stack(t_list *lst, char *s);

// stack_operators
void	ft_stack_swap(t_list **lst, char *s);
void	ft_stack_dswap(t_list **lst1, t_list **lst2);
void	ft_stack_push(t_list **lst1, t_list **lst2, char *s);

// lst_operators2
void	ft_stack_rotate(t_list **lst, char *s);
void	ft_stack_drotate(t_list **lst1, t_list **lst2);
void	ft_stack_rev_rotate(t_list **lst, char *s);
void	ft_stack_drev_rotate(t_list **lst1, t_list **lst2);

// quick_sort
void	ft_lstquick_sort(t_list **lst, int n);
void	ft_stack_move_to_right(t_list **lst, t_list *midle, int *mid, int cnt);
void	ft_stack_move_to_left(t_list **lst, t_list *midle, int *mid, int cnt);

// algo
void	algo1(t_stack *stk);

#endif