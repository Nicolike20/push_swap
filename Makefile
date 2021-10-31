# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nortolan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/04 10:42:17 by nortolan          #+#    #+#              #
#    Updated: 2021/10/28 15:26:09 by nortolan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_B = checker
cc = gcc
CFLAGS = -Wall -Werror -Wextra

SRCS = push_swap.c sort.c big_sort.c instructions1.c instructions2.c checks.c
SRCS_B = ps_bonus.c utils_bonus.c instructions1.c instructions2.c checks.c

OBJS_B = $(SRCS_B:%.c=%.o)
OBJS = $(SRCS:%.c=%.o)

PHONY. = all bonus clean fclean re

all: $(NAME) $(NAME_B)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) libft/libft.a

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(NAME_B)

$(NAME_B): $(OBJS_B)
	$(CC) $(CFLAGS) -o $(NAME_B) $(OBJS_B) libft/libft.a
clean:
	rm -rf $(OBJS)
	rm -rf $(OBJS_B)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(NAME_B)

re: fclean all
