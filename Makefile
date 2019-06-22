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

NAME		= libftprintf.a
NAME_PF		= ft_printf
COMPILER	= clang
CHECK_LEAK	= 
LIBFT			= src/libft/*.c
INCLUDES	=	includes/
SRC			=	src/ft_printf.c \
				src/init_format_specifier.c \
				src/format_specifier/integer.c \
				src/format_specifier/int_flag.c \
				src/format_specifier/int_precision.c \
				src/format_specifier/type_c.c \
				src/format_specifier/type_p.c \
				src/format_specifier/type_f.c \
				src/format_specifier/type_percent.c \
				src/format_specifier/ft_ftoa.c \
				src/format_specifier/type_s.c

UTILITY		=	src/utility/copy_until.c \
				src/utility/move_ptr.c \
				src/utility/ft_superjoin.c \
				src/utility/itoa64.c \
				src/utility/ft_itoa_base.c
ALL_OBJECT_FILES = $(SRC:.c=.o) $(UTILITY:.c=.o)
$(NAME):
	$(COMPILER) -c $(SRC) $(UTILITY) $(LIBFT) -I$(INCLUDES)
	ar rc $(NAME) *.o
	ranlib $(NAME)
clean:
	rm -f $(ALL_OBJECT_FILES) *.o
fclean: clean
	rm -f $(NAME) *.o

home:
	$(COMPILER) -o ft_printf test_ft_pf.c $(SRC) $(UTILITY) $(LIBFT) -I$(INCLUDES) -g
cheak_leaks:
	$(COMPILER) -fsanitize=address -g -o $(NAME) $(SRC) $(UTILITY) $(LIBFT) -I$(INCLUDES)