# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: famendes <famendes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 15:09:04 by famendes          #+#    #+#              #
#    Updated: 2024/11/12 19:30:28 by famendes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc

CFLAGS = -Werror -Wall -Wextra

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
