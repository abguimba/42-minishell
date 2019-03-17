# Project file
NAME = libft.a

# Project builds and dirs
SRCDIR = ./src/
SRCNAMES = ft_islower.c ft_lstnew.c ft_putchar.c ft_strcmp.c ft_strmapi.c\
ft_strsub.c ft_isprint.c ft_lstsize.c ft_putchar_fd.c ft_strcpy.c ft_strncat.c\
ft_strtrim.c ft_abs.c ft_isupper.c ft_memalloc.c ft_putendl.c ft_strdel.c\
ft_strncmp.c ft_swap.c ft_atoi.c ft_itoa.c ft_memccpy.c ft_putendl_fd.c\
ft_strdup.c ft_strncpy.c ft_tolower.c ft_bzero.c ft_lstadd.c ft_memchr.c\
ft_putnbr.c ft_strequ.c ft_strnequ.c ft_toupper.c ft_count_words.c\
ft_lstaddend.c ft_memcmp.c ft_putnbr_fd.c ft_striter.c ft_strnew.c\
get_next_line.c ft_intlen.c ft_lstbubblesort.c ft_memcpy.c ft_putstr.c\
ft_striteri.c ft_strnjoin.c ft_isalnum.c ft_lstdel.c ft_memdel.c ft_putstr_fd.c\
ft_strjoin.c ft_strnstr.c ft_isalpha.c ft_lstdelone.c ft_memmove.c ft_strcat.c\
ft_strlcat.c ft_strrchr.c ft_isascii.c ft_lstiter.c ft_memset.c ft_strchr.c\
ft_strlen.c ft_strsplit.c ft_isdigit.c ft_lstmap.c ft_only_digit.c ft_strclr.c\
ft_strmap.c ft_strstr.c ft_free.c ft_strfill.c ft_realloc_delete.c \
ft_cpy_delete.c ft_putstr_debug.c ft_putnbrendl.c ft_first_letter_search.c \
ft_realloc.c
SRC = $(addprefix $(SRCDIR), $(SRCNAMES))
INC = ./includes/
BUILDDIR = ./build/
BUILDOBJS = $(addprefix $(BUILDDIR), $(SRCNAMES:.c=.o))

# Optimization and Compiler flags and commands
CC = gcc
CFLAGS = -Wall -Werror -Wextra

# Debugging flags
DEBUG = -g -O0 -fsanitize=address \
-fno-omit-frame-pointer	\
-fsanitize-address-use-after-scope \
-fsanitize=undefined \

# Echo flags
ECHO = -ne

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
all: $(BUILDDIR) $(NAME)

# Object dir rule
$(BUILDDIR):
	@mkdir -p $(BUILDDIR)

# Objects rule
$(BUILDDIR)%.o:$(SRCDIR)%.c
	@$(CC) $(CFLAGS) -I$(INC) -o $@ -c $<
	@echo "\r                                                        \r\c"
	@echo "$(SOU)$< Compiled$(DEF)\c"

# Project file rule
$(NAME): $(BUILDOBJS)
	@echo "\r                                                         \r\c"
	@echo "$(WHI)LIBFT:$(DEF)"
	@echo "$(CYA)Libft Objects compiled$(DEF)"
	@ar rcs $(NAME) $(BUILDOBJS)
	@ranlib $(NAME)
	@echo "$(GRE)Libft.a Compiled and Indexed!$(DEFAULT)"

# Cleaning up the build files
clean:
	@rm -rf $(BUILDDIR)
	@echo "$(RED)Removed libft obj build dir and obj$(DEF)"

# Getting rid of the project file
fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED)Removed libft.a$(DEF)"

# Do both of the above
re: fclean all

# Just in case those files exist in the root dir
.PHONY: all fclean clean re
