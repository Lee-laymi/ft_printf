# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skrairab <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/21 20:06:15 by skrairab          #+#    #+#              #
#    Updated: 2022/06/01 20:56:54 by skrairab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 

NAME = libftprintf.a

SRCS = $(SRCS)

OBJS = $(SRCS: .c=o)

CC = gcc

CC_FLAGS = -c -Wall -Wextra -Werror

%.o:%.c
	$(CC) $(CC_FLAGE) -c $< -o $@

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
