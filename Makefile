
GREEN = \033[32m
RED = \033[31m
YELLOW = \033[33m
BLUE = \033[34m
MAGENTA = \033[35m
CYAN = \033[36m
WHITE = \033[37m
RESET = \033[0m

# # Variables
# CC = gcc
# CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

# NAME = minishell

# BUILTINS = envp.c builtin.c env.c pwd.c exit.c echo.c cd.c export.c var.c error.c

# EXEC = utils_exe.c execution.c fd.c fork.c

# TOKENIZING = tokenizing.c error.c utils_tok1.c split_tokens.c command.c \
# 	initialization.c utils_cmd.c path.c free.c utils_tok2.c signals.c
# MAIN = main.c 

# BUILTINS_DIR = builtins/
# EXEC_DIR = exec/
# PARSING_DIR = parsing/
# TOKENIZING_DIR = tokenizing/

# SRC = $(addprefix $(BUILTINS_DIR), $(BUILTINS)) \
# 		$(addprefix $(EXEC_DIR), $(EXEC)) \
# 		$(addprefix $(PARSING_DIR), $(PARSING)) \
# 		$(addprefix $(TOKENIZING_DIR), $(TOKENIZING)) \
# 		$(MAIN)
# SRC_DIR = srcs/
# SRC_OBJ = $(addprefix $(SRC_DIR), $(SRC:.c=.o))

# GET = get_next_line.c get_next_line_utils.c
# GET_DIR = get_next_line/
# GET_OBJ = $(addprefix $(GET_DIR), $(GET:.c=.o))

# INC_DIR = includes/
# INCLUDES = -I $(INC_DIR)



# LIBRL_DIR	=	$(INC_DIR)readline/
# LIBRL_H		=	chardefs.h history.h keymaps.h readline.h rlconf.h rlstdc.h rltypedefs.h tilde.h

# LIBFT_DIR = libft/
# LIBFT_OBJ = $(addprefix $(LIBFT_DIR), libft.a)

# # Minishell targets
# all: $(NAME)
# $(NAME): $(LIBFT_OBJ) $(GET_OBJ) $(SRC_OBJ)
# 	@echo "🔨$(CYAN) Compiled $@ $(DEFAULT)"
# 	@$(CC) $(CFLAGS) $(SRC_OBJ) $(LIBFT_OBJ) $(GET_OBJ) -lreadline $(LIBRL_DIR)libhistory.a  -o $@
# 	@echo "✅${GREEN} ${NAME} successfully created. 🌐${RESET}"
# # create "Libft/libft.a"
# $(LIBFT_OBJ):
# 	@make bonus -C $(LIBFT_DIR)
# # using SRC.c to create the SRC.o like "main.o", "check_input.o"...
# %.o: %.c
# 	@$(CC) $(CFLAGS) -o $@ -c $< -I.
# clean:
# 	@rm -f $(GET_OBJ) $(LIBFT_OBJ) $(SRC_OBJ)
# 	@make clean -C $(LIBFT_DIR)
# 	@echo "🧹 ${YELLOW} Binary files successfully removed 🗑${RESET}"
# fclean: clean
# 	@rm -f $(NAME)
# 	@echo "🧹 ${RED} Executables successfully removed 🗑${RESET}"
# re: fclean all

# # Declare targets as "phony"
# .PHONY: all clean fclean re lib lclean lfclean



# # windows 

#  Variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

NAME = minishell

BUILTINS = 	envp.c			\
			builtin.c		\
 			env.c			\
			pwd.c			\
			exit.c			\
			echo.c			\
			cd.c			\
			export.c		\
			var.c			\
			error.c			\
			utils_build.c	\
			unset.c			\

EXEC = 		utils_exe.c		\
			execution.c		\
			fd.c			\
			error_exc.c		\
			free_exe_fd.c	\

PARSING = 	command.c		\
			error.c			\
			free.c			\
			initialization.c\
			program.c		\
			signals.c		\
			split_tokens.c	\
			token_cmd.c		\
			token_here_doc.c\
			token_rdir.c	\
			uid.c			\
			utils_cmd.c		\
			utils_tok1.c	\
			utils_tok2.c	\
			utils_tok3.c	\
			utils_var.c		\

MAIN = main.c 

BUILTINS_DIR = builtins/
EXEC_DIR = exec/
PARSING_DIR = parsing/

SRC = $(addprefix $(BUILTINS_DIR), $(BUILTINS)) \
		$(addprefix $(EXEC_DIR), $(EXEC)) \
		$(addprefix $(PARSING_DIR), $(PARSING)) \
		$(MAIN)
SRC_DIR = srcs/
SRC_OBJ = $(addprefix $(SRC_DIR), $(SRC:.c=.o))

GET = get_next_line.c get_next_line_utils.c
GET_DIR = get_next_line/
GET_OBJ = $(addprefix $(GET_DIR), $(GET:.c=.o))

INC_DIR = includes/
INCLUDES = -I $(INC_DIR),

LIBRL_DIR	=	$(INC_DIR)librd/shlib/

LIBFT_DIR = libft/
LIBFT_OBJ = $(addprefix $(LIBFT_DIR), libft.a)

#  Minishell targets
all: $(NAME)
$(NAME): $(LIBFT_OBJ) $(GET_OBJ) $(SRC_OBJ)
	$(CC) $(CFLAGS) $(SRC_OBJ) $(GET_OBJ) $(LIBFT_OBJ) -o $@ -L$(LIBRL_DIR) -lreadline -lhistory  
#  create "Libft/libft.a"
$(LIBFT_OBJ):
	make bonus -C $(LIBFT_DIR)
#  using SRC.c to create the SRC.o like "main.o", "check_input.o"...
%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< -I.
clean:
	rm -f $(GET_OBJ) $(LIBFT_OBJ) $(SRC_OBJ)
	make clean -C $(LIBFT_DIR)
fclean: clean
	rm -f $(NAME)
re: fclean all

#  Declare targets as "phony"
.PHONY: all clean fclean re lib lclean lfclean