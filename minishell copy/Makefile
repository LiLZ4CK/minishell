# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zwalad <zwalad@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/29 14:48:17 by zwalad            #+#    #+#              #
#    Updated: 2022/07/23 21:19:18 by zwalad           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := minishell

CC := gcc

FLAGS := -Wall -Wextra -Werror

RM = @rm -f

C_RED = \033[1;31m
C_GREEN = \033[1;32m
C_L_BLUE = \033[1;34m
C_Yellow = \033[1;33m
C_Purple = \033[1;35m

EXEC := execut/builtins.c\
		execut/ft_utils_lib.c\
		execut/ft_echo.c\
		execut/ft_cd.c\
		execut/ft_env.c\
		execut/ft_export.c\
		execut/ft_split_ex_env.c\
		execut/ft_update_env.c\
		execut/ft_update_exp.c\
		execut/ft_exit.c\
		execut/ft_pwd.c\
		execut/ft_unset.c\
		execut/lib/ft_isalpha.c\
		execut/lib/ft_isalphanum.c\
		execut/lib/ft_split.c\
		execut/lib/ft_strchr.c\
		execut/lib/ft_strdup.c\
		execut/lib/ft_strjoin.c\
		execut/lib/ft_strlen.c\
		execut/lib/ft_strcmp.c\
		execut/lib/ft_substr.c\
		execut/lib/ft_error.c

SRC := main.c\
		sub_main.c\
		utils1.c\
		utils2.c\
		utils3.c\
		utils4.c\
		utils5.c\
		utils6.c\
		utils7.c\
		pipex_utils.c\


all: $(NAME)

$(NAME): $(SRC)
	@$(CC) $(SRC) $(EXEC) -o $(NAME) $(FLAGS) -lreadline -fsanitize=address -g
		@echo "$(C_RED)			      ___                       ___                       ___           ___           ___           ___       ___ "
		@echo "$(C_RED)			     /\__\\          ___        /\__\\          ___        /\  \         /\__\         /\  \         /\__\\     /\__\\"
	@echo "$(C_RED)			    /::|  |        /\  \      /::|  |        /\  \      /::\  \       /:/  /        /::\  \       /:/  /    /:/  /"
	@echo "$(C_RED)			   /:|:|  |        \:\  \    /:|:|  |        \:\  \    /:/\ \  \     /:/__/        /:/\:\  \     /:/  /    /:/  / "
	@echo "$(C_Purple)			  /:/|:|__|__      /::\__\  /:/|:|  |__      /::\__\  _\:\~\ \  \   /::\  \ ___   /::\~\:\  \   /:/  /    /:/  /  "
	@echo "$(C_Purple)			 /:/ |::::\__\  __/:/\/__/ /:/ |:| /\__\  __/:/\/__/ /\ \:\ \ \__\ /:/\:\  /\__\ /:/\:\ \:\__\ /:/__/    /:/__/   "
	@echo "$(C_Purple)			 \/__/~~/:/  / /\/:/  /    \/__|:|/:/  / /\/:/  /    \:\ \:\ \/__/ \/__\:\/:/  / \:\~\:\ \/__/ \:\  \    \:\  \   "
	@echo "$(C_Purple)			       /:/  /  \::/__/         |:/:/  /  \::/__/      \:\ \:\__\        \::/  /   \:\ \:\__\    \:\  \    \:\  \  "
	@echo "$(C_L_BLUE)			      /:/  /    \:\__\         |::/  /    \:\__\       \:\/:/  /        /:/  /     \:\ \/__/     \:\  \    \:\  \ "
	@echo "$(C_L_BLUE)			     /:/  /      \\/__/         |:/  /      \\/__/        \\::/  /        /:/  /       \\:\\__\        \\:\\__\    \\:\\__\\"
	@echo "$(C_L_BLUE)			     \/__/                     |/__/                     \/__/         \/__/         \/__/         \/__/     \/__/"
	@echo "$(C_L_BLUE)"
	@echo " "

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all





			