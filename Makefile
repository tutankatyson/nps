
# make -C <directorio donde hacer make"

NAME = push_swap

SRC =	push_swap.c \
		0_basic_op.c \
		0_double_op.c \
		1_tools_math.c \
		1_tools_basic.c \
		1_tools_error.c \
		1_tools_advanced.c \
		2_find_position.c \
		3_inserton.c \
		4_insert_best.c

OBJ =	push_swap.o \
		0_basic_op.o \
		0_double_op.o \
		1_tools_basic.o \
		1_tools_math.o \
		1_tools_advanced.o \
		1_tools_error.o \
		2_find_position.o \
		3_inserton.o \
		4_insert_best.o

LIB = ./lib/libftprintf.a

FLAGS = -Wall -Wextra -Werror


all: $(NAME)

$(NAME):fclean $(OBJ) $(LIB)
	@echo llamada a NAME:
	gcc $(OBJ) $(LIB) -o $(NAME)

$(OBJ):
	@echo llamada a OBJ:
	gcc $(FLAGS) -c $(SRC)

$(LIB):


clean:
	rm -f $(OBJ)
	rm -f ./lib/*.o

fclean:clean
	rm -f $(NAME)

push:
	git add .
	git status
	git commit -m "Last Commit"
	git push

py10: fclean $(NAME)
	python3 python_visualizer.py `ruby -e "puts (1..10).to_a.shuffle.join(' ')"`

py100: fclean $(NAME)
	python3 python_visualizer.py `ruby -e "puts (-49..50).to_a.shuffle.join(' ')"`
