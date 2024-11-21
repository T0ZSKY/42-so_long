# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tomlimon <tomlimon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/05 14:50:20 by tomlimon          #+#    #+#              #
#    Updated: 2024/11/21 15:03:54 by tomlimon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = event.c event2.c init_map.c init_map2.c map.c main.c verif_map.c verif_map2.c init_utils.c ennemi.c

PRINTF_SRCS = ./printf/ft_printf.c ./printf/ft_printchar.c ./printf/ft_printhex.c ./printf/ft_printnbr.c ./printf/ft_printpt.c ./printf/ft_printunsigned.c 
GNL_SRCS = ./gnl/get_next_line.c ./gnl/get_next_line_utils.c

ALL_SRCS = $(SRCS) $(PRINTF_SRCS) $(GNL_SRCS)

OBJS = $(ALL_SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
LDFLAGS = -L./minilibx-linux -lmlx -L/usr/lib -I./minilibx-linux -lXext -lX11 -lm -lz

YELLOW = \033[0;33m
GREEN = \033[0;32m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo -e "$(YELLOW)Compiling $(NAME)...$(RESET)"
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $(NAME)
	@echo -e "$(GREEN)Compilation successful!$(RESET)"

%.o: %.c
	@echo -e "$(YELLOW)Compiling $<...$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo -e "$(YELLOW)Cleaning object files...$(RESET)"
	rm -f $(OBJS)

fclean: clean
	@echo -e "$(YELLOW)Removing executable...$(RESET)"
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
