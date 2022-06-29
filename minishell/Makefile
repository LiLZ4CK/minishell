# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/29 14:48:17 by zwalad            #+#    #+#              #
#    Updated: 2022/06/29 15:25:16 by zwalad           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := minishell

CC := gcc

FLAGS := -Wall -Wextra -Werror

RM = @rm -f

SRC := main.c\
		utils1.c\
		utils2.c\
		utils3.c\
		utils4.c\


all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(SRC) -o $(NAME) $(FLAGS) libft.a -lreadline -g -fsanitize=address

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all