
# make -C <directorio donde hacer make"

# Nombre del programa
NAME       = push_swap
# Flags de compilacion
FLAGS      = -Wall -Wextra -Werror
# Directorios
SRC_DIR    = ./srcs/
OBJ_DIR    = ./obj/
INC_DIR    = ./includes/
LIBFT_DIR  = ./libft/

# Archivos fuentes
SRC_FILES  = push_swap.c \
		0_basic_op.c \
		0_double_op.c \
		1_tools_math.c \
		1_tools_error.c \
		1_tools_basic.c \
		1_tools_advanced.c \
		2_find_position.c \
		3_inserton.c \
		4_insert_best.c

BONUS_FILES  = 	0_basic_op.c \
			0_double_op.c \
			1_tools_math.c \
			1_tools_error.c \
			1_tools_basic.c \
			1_tools_advanced.c \
			2_find_position.c \
			3_inserton.c \
			4_insert_best.c \
			5_checker_bonus.c

# Objetos fuente, definidos cambiadno a SRC_FILES la extension .c por .o
OBJ_FILES  = $(SRC_FILES:.c=.o)
BONUS_OBJ_FILES  = $(BONUS_FILES:.c=.o)

# Direcciones
SRC        = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ        = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
BONUS_OBJ        = $(addprefix $(OBJ_DIR), $(BONUS_OBJ_FILES))
LIBFT      = $(addprefix $(LIBFT_DIR), libftprintf.a)

# Se compila el archivo binario (ejecutable).
all: obj $(NAME)

# Crea la carpeta donde estara los objetos.
obj:
	mkdir -p $(OBJ_DIR)

# Crea los objetos 
$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	gcc $(FLAGS) -o $@ -c $<

# Crea si es necesario la librería
$(LIBFT): 
	make -C $(LIBFT_DIR)

# Se compila los objetos con las librerias y archivos
$(NAME): $(OBJ) $(LIBFT)
	@echo " Compilando, espere unos segundos..."
	make -C $(LIBFT_DIR)
	gcc $(OBJ) $(LIBFT) -lm -o $(NAME)
	@echo "$(NAME) generado!"

# Remueve todos los archivos objetos
clean:
	rm -Rf $(OBJ_DIR)
	@echo "Objectos borrados!"

# Remueve todos los archivos objetos, binarios, y sus respectivas carpetas
fclean: clean 
	rm -f $(NAME)
	@echo "$(NAME) borrado!"

# Hace un re-make (como si se hubiera ejecutado Make por primera vez)
re: fclean all

# Le dice al make que estos nombre no son archivos
.PHONY: all clean fclean re push

bonus: obj $(BONUS_OBJ) $(LIBFT)
	@echo " Compilando BONUS, espere unos segundos..."
	make -C $(LIBFT_DIR)
	gcc $(BONUS_OBJ) $(LIBFT) -lm -o checker
	@echo "BONUS: checker generado!"


# Hace push a tu repositorio git online
push:
	git add .
	git status
	git commit -m "Last Commit"
	git push

# Bateria de test con el tester de python

py3: fclean all
	python3 python_visualizer.py `ruby -e "puts (-1..1).to_a.shuffle.join(' ')"`

py5: fclean all
	python3 python_visualizer.py `ruby -e "puts (-2..2).to_a.shuffle.join(' ')"`

py10: fclean all
	python3 python_visualizer.py `ruby -e "puts (1..10).to_a.shuffle.join(' ')"`

py100: all
	python3 python_visualizer.py `ruby -e "puts (-49..50).to_a.shuffle.join(' ')"`

py1000: all
	python3 python_visualizer.py `ruby -e "puts (-499..500).to_a.shuffle.join(' ')"`

















# Nombre del programa
#NAME       = <nombre>
# Flags de compilacion
#FLAGS      = -Wall -Wextra -Werror -g -Ofast
# Directorios
#SRC_DIR    = ./srcs/
#OBJ_DIR    = ./obj/
#INC_DIR    = ./includes/
#LIBFT_DIR  = ./libft/
#MINLBX_DIR = ./minilibx/
## Archivos fuentes y objetos
#SRC_FILES  = $(wildcard $(SRC_DIR)/*.c)
#OBJ_FILES  = $(SRC_FILES:.c=.o)
## Direcciones
#SRC        = $(addprefix $(SRC_DIR), $(SRC_FILES))
#OBJ        = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
#LIBFT      = $(addprefix $(LIBFT_DIR), libft.a)
#MINLBX     = $(addprefix $(MINLBX_DIR), libmlx.a)
## Linkers
#LNK        = -Ofast 
# Se compila el archivo binario (ejecutable).
#all: obj $(NAME)
# Crea la carpeta donde estara los objetos.
#obj:
#   @mkdir -p $(OBJ_DIR)
#$(OBJ_DIR)%.o:$(SRC_DIR)%.c
#   @gcc $(FLAGS) -I $(INC_DIR) -o $@ -c $<
## Se compila los objetos con las librerias y archivos
#$(NAME): $(OBJ)
#   @echo "(ﾉ◕ヮ◕)ﾉ*:・ﾟ✧ Compilando, espere unos segundos..."
#   @gcc $(OBJ) $(LNK) -lm -o $(NAME)
#   @echo "(•̀ᴗ•́)و $(NAME) generado!"
## Remueve todos los archivos objetos
#clean:
#   @rm -Rf $(OBJ_DIR)
#   @echo "¯\_(ツ)_/¯ Objectos removidos!"
## Remueve todos los archivos objetos, binarios, y sus respectivas carpetas
#fclean: clean
#   @rm -f $(NAME)
#   @echo "(╯°□°）╯︵ ┻━┻ $(NAME) removido!"
## Hace un re-make (como si se hubiera ejecutado Make por primera vez)
#re: fclean all
## Le dice al make que estos nombre no son archivos
#.PHONY: all clean fclean re
