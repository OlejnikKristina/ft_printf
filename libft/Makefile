NAME			= libft.a
CFLAGS			= -Wall -Werror -Wextra

FAVORITE		:= atoi itoa ftoa itoa_base
LST				:= lstadd lstdel lstdelone lstiter lstmap lstnew
MEM				:= bzero memalloc memcpy memccpy memcmp memchr memdel memmove memset
OTHER			:= count_digit foreach isalnum isprint isalpha isascii \
				isdigit range recursive_factorial tolower toupper
PUT				:= putchar putchar_fd putendl_fd putendl putnbr_fd putnbr putstr_fd putstr
STR				:= sqrt strcat strcmp strcpy strdup strlen strncat strncmp \
				strncpy strnstr strrchr strstr strchr strlcat strnew strdel strclr \
				striter striteri strmap strmapi strequ strnequ strsub strsplit strjoin \
				superjoin strrev
SPECIFIC_NAME	:= other/kr_count_words other/space favorite/findchr favorite/itoa64

OBJ			:=  $(addsuffix .o, $(addprefix ft_, $(FAVORITE) $(LST) $(MEM) $(OTHER) $(STR) $(PUT))) \
				findchr.o kr_count_words.o space.o itoa64.o

FAVORITE	:= $(addprefix favorite/, $(addprefix ft_, $(FAVORITE)))
LST			:= $(addprefix lst/, $(addprefix ft_, $(LST)))
MEM			:= $(addprefix mem/, $(addprefix ft_, $(MEM)))
OTHER		:= $(addprefix other/, $(addprefix ft_, $(OTHER)))
PUT			:= $(addprefix put/, $(addprefix ft_, $(PUT)))
STR			:= $(addprefix str/, $(addprefix ft_, $(STR)))

SRC			:=  $(FAVORITE) $(LST) $(MEM) $(OTHER) $(PUT) \
				$(STR) $(SPECIFIC_NAME)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "\033[0;32mCreate libft.a from object files\033[0m"
	@ranlib $(NAME)

$(OBJ):
	@clang $(CFLAGS) -c $(addsuffix .c, $(SRC)) -I includes/
	@echo "\033[0;32mLinking. Create objects file for libft.a\033[0m"

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

so:
	gcc -shared -o $(NAME) $(OBJ)

.PHONY: clean fclean all re
