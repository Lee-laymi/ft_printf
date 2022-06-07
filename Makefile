# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skrairab <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/21 20:06:15 by skrairab          #+#    #+#              #
#    Updated: 2022/06/07 02:00:33 by skrairab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c

NAME = libftprintf.a

#SRCS = $(SRCS)

#OBJS = $(SRCS:%.c=o)
OBJS = ft_printf.o

CC = gcc

CC_FLAGS = -c -Wall -Wextra -Werror

#%.o:%.c
#	$(CC) $(CC_FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CC_FLAGS) $(SRCS)
	ar -rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
