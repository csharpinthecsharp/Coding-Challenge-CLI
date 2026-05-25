NAME	= learn
CPP	= c++
CFLAGS	= -std=c++98 -g -Wall -Wextra -Werror

SRCS	= src/main.cpp \
		  src/cpp_files/Profile.cpp \
		  src/cpp_files/Level.cpp \
		  src/cpp_files/Chapter.cpp \
		  src/cpp_files/Interface.cpp

OBJS	= $(SRCS:.cpp=.o)

GREEN = \033[0;32m
BOLD = \033[1m
RESET = \033[0m

all: $(NAME)
	@echo ""
	@echo "$(GREEN)$(BOLD) ==== ./learn to run ====$(RESET)"
	@echo ""

%.o: %.cpp
	$(CPP) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CPP) $(CFLAGS) $(OBJS) -o $(NAME) -lncurses -ltinfo

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	make clean

re: fclean all

.PHONY: all clean fclean re