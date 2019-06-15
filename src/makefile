# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: krioliin <krioliin@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/05/28 23:58:48 by krioliin       #+#    #+#                 #
#    Updated: 2019/05/28 23:58:48 by krioliin      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		= ft_printf
COMPILER	= clang
CHECK_LEAK	= 
LIB			= libft/libft.a
INCLUDES	= ../includes/
SRC			=	ft_printf.c \
				init_format_specifier.c \
				format_specifier/d/integer.c \
				format_specifier/d/set_flag_d.c \
				format_specifier/d/set_precision.c
UTILITY		=	utility/copy_until.c \
				utility/move_ptr.c \
				utility/ft_superjoin.c \
				utility/pf_itoa.c

home:
	$(COMPILER) -o $(NAME) $(SRC) $(UTILITY) $(LIB) -I$(INCLUDES)
cheak_leaks:
	$(COMPILER) -fsanitize=address -g -o $(NAME) $(SRC) $(UTILITY) $(LIB) -I$(INCLUDES)