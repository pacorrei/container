MINE = ft_container

REAL = std_container

XX = clang++

XXFLAGS = -Wall -Werror -Wextra -std=c++98 -fsanitize=address -g3

HEADER = -I ./include/

SRCS = main.cpp

MINE_OBJ = $(SRCS:cpp=o)

REAL_OBJ = std_main.o

VALUE = 0
$(SET_VALUE):
		$(VALUE) = 1
all: $(MINE) $(REAL)

$(MINE): $(MINE_OBJ)
	$(XX) $(XXFLAGS) ${HEADER} -o $(MINE) $(MINE_OBJ)

$(REAL): $(REAL_OBJ)
	$(XX) $(XXFLAGS) ${HEADER} -o $(REAL) std_main.o

std_main.o:
	${XX} -D SPACE=std ${XXFLAGS} ${HEADER} -c main.cpp -o std_main.o
%.o: %.cpp
ifeq ($(VALUE), 0)
	${XX} -D SPACE=ft ${XXFLAGS} ${HEADER} -c $< -o $@
else
	${XX} -D SPACE=std ${XXFLAGS} ${HEADER} -c $< -o std_main.o
endif

clean:
	rm -f $(MINE_OBJ) $(REAL_OBJ)

fclean:
	rm -f $(MINE_OBJ) $(REAL_OBJ)
	rm -f $(MINE) $(REAL)

re: fclean all

.PHONY: clean fclean re test norm