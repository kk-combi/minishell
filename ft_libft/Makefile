NAME = libft.a

SOURCES = \
	ft_atoi.c ft_memset.c ft_strlcpy.c \
	ft_bzero.c ft_putchar_fd.c ft_strlen.c \
	ft_calloc.c ft_putendl_fd.c ft_strmapi.c \
	ft_isalnum.c ft_putnbr_fd.c ft_strncmp.c \
	ft_isalpha.c ft_putstr_fd.c ft_strnstr.c \
	ft_isascii.c ft_split.c ft_strrchr.c \
	ft_isdigit.c ft_strchr.c ft_strtrim.c \
	ft_isprint.c ft_memchr.c ft_strdup.c ft_substr.c \
	ft_itoa.c ft_memcmp.c ft_striteri.c	ft_tolower.c \
	ft_memcpy.c ft_strjoin.c ft_toupper.c \
	ft_memmove.c ft_strlcat.c \
	ft_lstadd_back_bonus.c   ft_lstclear_bonus.c   ft_lstiter_bonus.c  ft_lstmap_bonus.c  ft_lstsize_bonus.c \
	ft_lstadd_front_bonus.c  ft_lstdelone_bonus.c  ft_lstlast_bonus.c  ft_lstnew_bonus.c \
	ft_print_char.c ft_strcmp.c ft_putstr.c ft_putendl.c \
	ft_printf.c \
	ft_print_int.c \
	ft_print_ptr.c  \
	ft_print_str.c \
	ft_print_uint.c \
	ft_print_hint.c \
	get_next_line.c \
	get_next_line_utils.c

INCLUDES = ../includes

OBJS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(INCLUDES)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) -r $@ $?

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
