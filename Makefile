NAME	= c_learner
CC		= clang
CFLAGS	= -g -Wall -Wextra -Werror

SRCS	= main.c \
		  data.c \
		  terminal.c \
		  commands.c

OBJS	= $(SRCS:.c=.o)
all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) -lreadline $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re