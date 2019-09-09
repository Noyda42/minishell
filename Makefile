# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/15 13:17:50 by temehenn          #+#    #+#              #
#    Updated: 2019/09/09 20:45:08 by temehenn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=minishell
CC=gcc
LIBFTDIR= ./libft
SRCDIR = src
OBJDIR = obj
FLAGS= -Wall -Wextra -Werror -g
SRCFILE = 	main.c \
			manage_error.c \
			ft_getopt.c\
			echo.c\
			free_func.c\
			copy_tab.c\
			print_error.c\
			create_env_list.c\
			print_env.c

SRC = $(addprefix $(SRCDIR), $(SRCFILE))
OBJFILE = $(SRCFILE:.c=.o)
OBJ = $(addprefix $(OBJDIR)/,$(OBJFILE))

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC)  -o $(NAME) $(OBJ) ./libft/libft.a
	@echo "\033[32mCompilation SUCCEED. Binary created :\033[32;1m" $@

$(OBJ): | $(OBJDIR)

$(OBJDIR):
	@make -C libft/
	@mkdir $@

$(OBJDIR)/%.o :$(SRCDIR)/%.c
	@$(CC) $(FLAGS) -o $@ -c $< -I include/ -I $(LIBFTDIR)
	@echo "File compiled : " $<

clean:
	@make -C libft/ clean
	@rm -rf $(OBJDIR)
	@echo "\033[36mObjects have been deleted.\033[00m"

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)
	@echo "\033[36m"$(NAME) "have been deleted.\033[00m"

re: fclean all

.PHONY: all clean fclean re
