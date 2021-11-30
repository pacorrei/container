NAME = Container

CC = clang++ $(CFLAG)

SRCS = main.cpp \

OBJS = $(SRCS:.cpp=.o)

CFLAG = -Wall -Wextra -Werror -std=c++98
all : $(NAME)

%.o : %.cpp
	$(CC) -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re