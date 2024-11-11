# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: famendes <famendes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 15:09:04 by famendes          #+#    #+#              #
#    Updated: 2024/11/11 15:17:34 by famendes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc

CFLAGS = -Werror -Wall -Wextra -s

RM = rm -rf

SRCS = 	main.c\
		utils.c\

OBJ = $(SRCS:.c=.o)

LIBFT = Libft/libft.a

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C Libft

all : $(NAME)

clean :
	$(RM) $(OBJ) $(OBJ_BONUS)
	make clean -C Libft

fclean : clean
	$(RM) $(NAME)
	make fclean -C Libft

re : fclean all
