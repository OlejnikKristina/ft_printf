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
COMPILER	= clang-6.0
CHECK_LEAK	= 
LIB			= libft/libft.a
SRC			=	ft_printf.c
INCLUDES	= ../includes/
UTILITY		=	utility/copy_until.c \
				utility/move_ptr.c \

home:
	$(COMPILER) -o $(NAME) $(SRC) $(UTILITY) $(LIB) -I$(INCLUDES)
cheak_leaks:
	$(COMPILER) -fsanitize=address -g -o $(NAME) $(SRC) $(UTILITY) $(LIB) -I$(INCLUDES)