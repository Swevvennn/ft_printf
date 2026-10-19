CC = cc
CFLAGS = -Wall -Wextra -Werror
SOURCES = ft_printf.c ft_send.c
OBJECTS = $(SOURCES:.c=.o)
INCLUDES = ft_printf.h
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all