# Project file
NAME = minishell

# Project builds and dirs
SRCDIR = ./src/
SRCNAMES = main.c env.c utils.c line_formatter.c line_formatter_2.c boe.c \
echo.c exit.c errors.c create_env.c setenv.c unsetenv.c utils_2.c \
ft_strsplit_minishell.c ft_strjoin_minishell.c utils_3.c \
builtin_searchers.c utils_4.c setenv_2.c utils_13.c signal_handlers.c \
builtin_searchers_2.c cd.c errors_2.c utils_5.c cd_2.c utils_6.c exec.c \
utils_7.c utils_8.c utils_9.c exec_2.c utils_10.c utils_11.c \
commands_parser.c utils_12.c errors_3.c
SRC = $(addprefix $(SRCDIR), $(SRCNAMES))
INC = ./inc/
BUILDDIR = ./build/
BUILDOBJS = $(addprefix $(BUILDDIR), $(SRCNAMES:.c=.o))

# Libft builds and dirs
LIBDIR = ./libft/
LIBFT = ./libft/libft.a
LIBINC = ./libft/includes/

# Optimization and Compiler flags and commands
CC = gcc
CFLAGS = -Wall -Werror -Wextra

# Debugging flags
DEBUG = -g3 -O3 -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls \
-fno-omit-frame-pointer -fsanitize-address-use-after-scope -fsanitize=undefined

DEF =		\033[0m
GRA =		\033[1m
SOU =		\033[4m
BLI =		\033[5m
BLA =		\033[30m
RED =		\033[31m
GRE =		\033[32m
YEL =		\033[33m
BLU =		\033[34m
PUR =		\033[35m
CYA =		\033[36m
WHI =		\033[37m

# Main rule
all: $(BUILDDIR) $(LIBFT) $(NAME)

# Object dir rule
$(BUILDDIR):
	@mkdir -p $(BUILDDIR)

# Objects rule
$(BUILDDIR)%.o:$(SRCDIR)%.c
	@$(CC) $(CFLAGS) -I$(LIBINC) -I$(INC) -o $@ -c $<
	@echo "\r                                                                                \r\c"
	@echo "$(SOU)$< Compiled$(DEF)\c"

# Project file rule
$(NAME): $(BUILDOBJS)
	@echo "\r                                                                                \r\c"
	@echo "$(WHI)MINISHELL:$(DEF)"
	@echo "$(CYA)Minishell Objects compiled$(DEF)"
	@$(CC) $(CFLAGS) -o $(NAME) -g3 $(BUILDOBJS) $(LIBFT)
	@echo "$(GRE)minishell executable Compiled and Ready!$(DEF)"

# Libft rule
$(LIBFT):
	@make -C $(LIBDIR)

# Cleaning up the build files
clean:
	@rm -rf $(BUILDDIR)
	@echo "$(RED)Removed minishell obj build dir and obj$(DEF)"

# Getting rid of the project file
fclean: clean
	@rm -rf $(NAME)
	@make -C $(LIBDIR) fclean
	@echo "$(RED)Removed minishell executable$(DEF)"

# Do both of the above
re: fclean all

# Just in case those files exist in the root dir
.PHONY: all fclean clean re
