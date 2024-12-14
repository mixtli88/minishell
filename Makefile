# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = minishell

BUILTINS = builtin.c 
EXEC = exec.c 
PARSING = parsing.c 
TOKENIZING = tokenizing.c 
MAIN = main.c 

BUILTINS_DIR = builtins/
EXEC_DIR = exec/
PARSING_DIR = parsing/
TOKENIZING_DIR = tokenizing/

SRC = $(addprefix $(BUILTINS_DIR), $(BUILTINS)) \
		$(addprefix $(EXEC_DIR), $(EXEC)) \
		$(addprefix $(PARSING_DIR), $(PARSING)) \
		$(addprefix $(TOKENIZING_DIR), $(TOKENIZING)) \
		$(MAIN)
SRC_DIR = srcs/
SRC_OBJ = $(addprefix $(SRC_DIR), $(SRC:.c=.o))

GET = get_next_line.c get_next_line_utils.c
GET_DIR = get_next_line/
GET_OBJ = $(addprefix $(GET_DIR), $(GET:.c=.o))

INC_DIR = includes/
INCLUDES = -I $(INC_DIR)

LIBFT_DIR = Libft/
LIBFT_OBJ = $(addprefix $(LIBFT_DIR), libft.a)

# Minishell targets
all: $(NAME)
$(NAME): $(LIBFT_OBJ) $(GET_OBJ) $(SRC_OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(LIBFT_OBJ) $(GET_OBJ) $(SRC_OBJ) -o $@
# create "Libft/libft.a"
$(LIBFT_OBJ):
	make bonus -C $(LIBFT_DIR)
# using SRC.c to create the SRC.o like "main.o", "check_input.o"...
%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< -I.
clean:
	rm -f $(GET_OBJ) $(LIBFT_OBJ) $(SRC_OBJ)
	make clean -C $(LIBFT_DIR)
fclean: clean
	rm -f $(NAME)
re: fclean all

# Declare targets as "phony"
.PHONY: all clean fclean re lib lclean lfclean