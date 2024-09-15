##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

CC		?= 		g++

SRC 	= 		src/main.cpp \
				src/linked.cpp \
				src/put_error.cpp \
				src/get_buffer_file.cpp \
				src/extract_str_quote.cpp \
				src/get_info.cpp \
				src/error_handling.cpp \
				src/execute_binarie.cpp \
				src/parse_each_file.cpp \
				src/declaration.cpp \
				src/manage_event.cpp \
				src/game_loop.cpp \
				src/setup_game.cpp \
				src/choose_random_player.cpp

OBJ 	= 		$(SRC:.cpp=.o)

NAME 	= 		parser

CFLAGS 	= 		-W -Wall -Wextra

CPPFLAGS = 		-I ./include

LDLIBS 	= 		-lstdc++ -lsfml-graphics -lsfml-window -lsfml-system

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDLIBS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

debug: CFLAGS += -g3
debug: re
	gdb -ex "run" -ex "bt full" -ex "detach" -ex "quit" --args $(NAME) $(arg)

.PHONY: all clean fclean re debug
