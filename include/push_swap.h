#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "libft.h"

# define DEBUG 1
# define OUT 1

# define SA "sa"
# define SB "sb"
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
	t_list	*sorted;
	int		lena;
	int		lenb;
	int		maxa;
	int		q1;
	int		q2;
	int		q3;
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

// quick_sort (not used)

void	ft_lstquick_sort(t_list **lst, int n);
void	ft_stack_move_to_right(t_list **lst, t_list *midle, int *mid, int cnt);
void	ft_stack_move_to_left(t_list **lst, t_list *midle, int *mid, int cnt);

// algoritm_merge

void	alg2(t_stack *stk, int len);
void	alg2_merge(t_stack *stk, int len, int group_size);
void	alg2_push_to_b(t_stack *stk, int len, int gs);
void	alg2_small(t_stack *stk, int len);

// algoritm_wheel

void	alg_wheel(t_stack *stk, int len);
void	find_quartiles(t_stack *stk, int len);
void	move_to_b(t_stack *stk, int len);

#endif