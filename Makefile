CC = cc

CFLAGS = -Wall -Wextra -Werror
NAME = philosophers

SRCS = src/init.c src/main.c src/utils.c src/life_cycle.c src/control.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	rm -r $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

