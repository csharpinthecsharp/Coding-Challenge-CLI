NAME	= c_learner
CC		= clang
CFLAGS	= -g -Wall -Wextra -Werror

SRCS	= main.c \
		  data_hdl/data_settings.c \
		  data_hdl/data_exercice.c \
		  commands.c \
		  terminal_hdl/term_cli.c \
		  terminal_hdl/term_settings.c \

OBJS	= $(SRCS:.c=.o)
all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) -lreadline -ltinfo $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re