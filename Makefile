# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abnaciri <abnaciri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/08 20:39:20 by abnaciri          #+#    #+#              #
#    Updated: 2024/06/08 20:39:21 by abnaciri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
HEADER = fractol.h
CFLAGS = -Wall -Wextra -Werror
LDLIBS = -lmlx -framework OpenGL -framework AppKit
CC = cc
RM = rm -f
AR = ar crs
SRC = coloring.c \
	drawing.c \
	hooks.c \
	main.c \
	fractol_maths.c \
	libft.c \
	ft_strncmp.c \
	utils.c \
	utils2.c

OBJ = $(SRC:.c=.o)
all : $(NAME)
$(NAME) : $(OBJ)
	$(CC) $(LDLIBS) $(CFLAGS) $(OBJ) -o $(NAME)
%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ)
fclean : clean
	$(RM) $(NAME)
re : fclean all
.PHONY : all clean fclean re