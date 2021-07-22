NAME		=	push_swap
NAME_M		=	push_swap_merge
NAME_B		=	checker

SRCS_FILES	= 	push_swap.c \
				parcing.c \
				raise_error.c \
				stack_operator1.c \
				stack_operator2.c \
				quick_sort.c \
				algo_wheel.c \
				algo_wheel_prepair.c \
				algo_wheel_move_back.c \
				algo_merge.c \

SRCS_MERGE	= 	push_swap_merge.c \
				parcing.c \
				raise_error.c \
				stack_operator1.c \
				stack_operator2.c \
				algo_merge.c \

SRCS_B_F	=	checker.c \
				parcing.c \
				raise_error.c \
				stack_operator1.c \
				stack_operator2.c \
				gnl/get_next_line.c 


SRCS_FOLDER	=	source/
SRCS_B_FLD	=	source_bonus/
HEADER		=	include/push_swap.h

SRCS		= 	$(addprefix $(SRCS_FOLDER),$(SRCS_FILES))
SRCS_M		=	$(addprefix $(SRCS_FOLDER),$(SRCS_MERGE))
SRCS_B		=	$(addprefix $(SRCS_B_FLD),$(SRCS_B_F))
OBJS		=	$(patsubst %.c,%.o,$(SRCS))
OBJS_M		=	$(patsubst %.c,%.o,$(SRCS_M))
OBJS_B		=	$(patsubst %.c,%.o,$(SRCS_B))

INCLUDE		=	-I./include -I./libs/libft/

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -MMD
RM			=	rm -f

LIB = ./libs/libft/libft.a

all:		$(NAME)

bonus:		$(NAME_B)

merge:		$(NAME_M)

%.o:		%.c
			$(CC) $(CFLAGS) $(INCLUDE) -c -g $< -o $@
		
$(NAME):	$(OBJS)
			$(MAKE) -C $(dir $(LIB))
			$(CC) $(INCLUDE) -o $(NAME) $(OBJS) $(LIB)

$(NAME_M):	$(OBJS_M)
			$(MAKE) -C $(dir $(LIB))
			$(CC) $(INCLUDE) -o $(NAME_M) $(OBJS_M) $(LIB)

$(NAME_B):	$(OBJS_B)
			$(MAKE) -C $(dir $(LIB))
			$(CC) $(INCLUDE) -o $(NAME_B) $(OBJS_B) $(LIB)

clean:
			$(RM) $(OBJS) $(OBJS:.o=.d)
			$(RM) $(OBJS_M) $(OBJS_M:.o=.d)
			$(RM) $(OBJS_B) $(OBJS_B:.o=.d)
			@make -C $(dir $(LIB)) clean

fclean:		clean
			@make -C $(dir $(LIB)) fclean
			$(RM) $(NAME) $(NAME_M) $(NAME_B)

re:			fclean all

.PHONY:		all clean fclean re bonus merge
-include	$(OBJS:.o=.d)
-include	$(OBJS_M:.o=.d)
-include	$(OBJS_B:.o=.d)