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

NAME		=	libftprintf.a
NAME_PF		=	ft_printf
COMPILER	=	gcc
CHECK_LEAK	= 
LIBFT		=	libft/favorite/*.c libft/mem/*.c \
				libft/lst/*.c libft/other/*.c \
				libft/put/*.c libft/str/*.c
INCLUDES	=	includes/
SRC			=	src/ft_printf.c \
				src/init_format_specifier.c \
				src/integer.c \
				src/int_flag.c \
				src/int_precision.c \
				src/add_zeros.c \
				src/type_c.c \
				src/type_p.c \
				src/type_f.c \
				src/type_percent.c \
				src/pf_colors.c \
				src/type_s.c

UTILITY		=	src/copy_until.c \
				src/move_ptr.c

ALL_OBJECT_FILES = $(SRC:.c=.o) $(UTILITY:.c=.o)

all: $(NAME)

$(NAME):
	@$(COMPILER) -c $(SRC) $(UTILITY) $(LIBFT) -I$(INCLUDES)
	@echo "\033[0;32mLinking objects files for ft_printf and libft \033[0m"
	@ar rc $(NAME) *.o
	@ranlib $(NAME)
clean:
	@rm -f $(ALL_OBJECT_FILES) *.o
	@echo "\033[0;33mRemove objects files from ft_printf\033[0m"
	@make -C libft/ clean
fclean: clean
	@rm -f $(NAME) *.o && make -C libft/ fclean
home:
	@$(COMPILER) -o ft_printf test_ft_pf.c $(SRC) $(UTILITY) libft/libft.a -I$(INCLUDES) -g
	@echo "\033[0;32mCompiling all files\033[0m"
re: fclean all