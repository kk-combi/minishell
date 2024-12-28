NAME = minishell
LIBFTNAME = libft.a
LIBFTDIR = ./ft_libft
INCLUDES = includes
SOURCES = \
	built_cmd1.c built_cmd5.c exec_bin.c insert_var_utils.c minishell_utils4.c parse_utils2.c shell_level.c \
	built_cmd2.c built_cmd6.c exec_cmd_utils2.c main.c minishell_utils5.c parse_utils3.c shell_level_utils.c \
	built_cmd3.c check_line.c exec_cmd_utils.c minishell_utils2.c minishell_utils.c parse_utils4.c signal.c \
	built_cmd4.c env_init.c free_token.c minishell_utils3.c parse.c parse_utils.c \

OBJS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(INCLUDES)

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFTDIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFTDIR)/$(LIBFTNAME) -lreadline -lncurses -o $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	make clean -C $(LIBFTDIR)
	$(RM) $(OBJS)

fclean: clean
	make fclean -C $(LIBFTDIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
