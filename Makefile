# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcervill <pcervill@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/12 09:52:26 by pcervill          #+#    #+#              #
#    Updated: 2023/02/28 12:33:15 by pcervill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Werror -Wextra #-g -fsanitize=address -g3

SRC_DIR = ./src

SRCS = push_swap.c arguments.c utils.c utils_maxmin.c utils_posmaxmin.c \
		movs1.c movs2.c movs3.c sort.c algoritm2_3_5.c algoritm100-500.c

OBJS = $(addprefix $(SRC_DIR)/, ${SRCS:.c=.o})

NAME = push_swap

LIBFT_PATH = ./libft/

all:		$(NAME)
			@echo " \033[32m[ OK ] | Push_swap ready!\033[0m"

$(NAME):	$(OBJS)
			@echo " \033[33m[ .. ] | Compiling libft..\033[0m"
			make bonus -C $(LIBFT_PATH)
			@echo " \033[32m[ OK ] | Libft ready!\033[0m"
			@echo " \033[33m[ .. ] | Compiling push_swap..\033[0m"
			$(CC) -L $(LIBFT_PATH) -l ft $(CFLAGS) $(OBJS)  -o $(NAME)
			

run:
			./$(NAME) 265

clean:
			make clean -C $(LIBFT_PATH)
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)
			make fclean -C $(LIBFT_PATH)
			@echo " \033[1;31m[ OK ] | Push_swap fclean ready!\033[0m"

re:			fclean all

.PHONY =	all clean fclean re
.SILENT: $(OBJS)