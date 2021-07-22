#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "libft.h"

# define DEBUG 0
# define OUT 1

# define SA			"sa"
# define SB			"sb"
# define RA			"ra"
# define RB			"rb"
# define RRA		"rra"
# define RRB		"rrb"
# define PA			"pa"
# define PB			"pb"
# define RA_RB		0
# define RRA_RRB	1
# define RA_RRB		2
# define RRA_RB		3

typedef struct s_step
{
	int	ra;
	int	rra;
	int	rb;
	int	rrb;
	int	total;
	int	mode;
}	t_step;

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
	t_step	step;
}	t_stack;

//parcing

void	parcing_args(int n, char **argv, t_stack *stk);

// raise_error

void	ft_raise_error(char *s);
int		ft_maxint(int a, int b);
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

// algo_merge

void	alg2_merge(t_stack *stk, int len);
void	alg2_merge_blocks(t_stack *stk, int len, int group_size);
void	alg2_push_to_b(t_stack *stk, int len, int gs);
void	alg2_small(t_stack *stk, int len);

// algo_wheel

void	alg_wheel(t_stack *stk, int len);
void	shift_to_begin(t_stack *stk);

// algo_wheel_move_back

void	move_elem_from_b(t_stack *stk);
int		get_place_in_a(t_stack *stk, int bx);
void	search_shortest_way(t_stack *stk, t_step *step);
void	update_short_way(t_stack *stk, t_step *step, int mode, int total);
void	prepare_stacks(t_stack *stk, t_step step);

// algo_wheel_preprocecing

void	find_quartiles(t_stack *stk, int len);
void	move_to_b(t_stack *stk, int len);
void	move_4block_to_b(t_stack *stk, int len);

#endif