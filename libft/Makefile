# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jorsanch <jorsanch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/30 18:15:47 by jorsanch          #+#    #+#              #
#    Updated: 2023/01/14 00:34:23 by jorsanch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nombre del programa
NAME = libftprintf.a

# Flags de compilacion
FLAGS      = -Wall -Wextra -Werror

# Directorios
SRC_DIR    = ./src/
OBJ_DIR    = ./obj/
INC_DIR    = ./includes/

# Archivos fuentes
SRC_FILES  = ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
	 		ft_isascii.c \
	 		ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_split.c \
			ft_strchr.c \
			ft_strdup.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_putnbrbase.c \
			ft_uitoa.c \
			get_next_line.c \
			get_next_line_utils.c


# Objetos fuente, definidos cambiando a SRC_FILES la extension .c por .o
OBJ_FILES  = $(SRC_FILES:.c=.o)

# Direcciones. Formadas con añadiendo el prefijo direccion al nombre del archivo .c y .o
SRC        = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ        = $(addprefix $(OBJ_DIR), $(OBJ_FILES))


# Se compila el archivo binario (ejecutable).
all: obj $(NAME)

# Crea la carpeta donde estara los objetos.
obj:
	mkdir -p $(OBJ_DIR)
	
# Crea los objetos 
$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	gcc $(FLAGS) -o $@ -c $<

# Se compila los objetos con las librerias y archivos
$(NAME): $(OBJ)
	@echo " Compilando, espere unos segundos..."
	ar -crs $(NAME) $(OBJ)
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

# Hace push a tu repositorio git online
push:
	git add .
	git status
	git commit -m "Last Commit"
	git push
