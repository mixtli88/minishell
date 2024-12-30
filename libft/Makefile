CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99
NAME = libft.a
SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
	ft_isdigit.c ft_isprint.c ft_isint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
	ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
	ft_strncmp.c  ft_strrchr.c ft_tolower.c ft_toupper.c ft_strnstr.c \
	ft_split.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c \
	ft_strjoin.c ft_substr.c ft_strtrim.c ft_strmapi.c ft_striteri.c ft_isaspace.c
OBJ = $(SRC:.c=.o)

BONUS_SRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
	ft_lstdelone.c ft_lstrm_last.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)
# "all" is a target

# Rule to build the executable
$(NAME): $(OBJ)
	ar rcs $@ $^
# "$(OBJ)" is a dependency, which need to exist before the commands for the target are run
# dependency MUST be a target defined in other line
# "ar rcs $@ $^" is a command
# "$@" is an automatic variable that represents the target name, here is $(NAME)
# "$^" is an automatic variable that represents all the dependencies separated by spaces, here is $(OBJ)

bonus: $(OBJ) $(BONUS_OBJ)
	ar rcs $(NAME) $^

# Rule to build object files
%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< -I.
# "$<" is an automatic variable that represents the first dependency, here is %.c
# "-I." means include the current directory for header file search

clean:
	rm -f $(OBJ) $(BONUS_OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all

tclean: fclean
	rm -f test main.o
test: tclean $(NAME)
	$(CC) -o main.o -c main.c -I.
	$(CC) -o $@ main.o libft.a
