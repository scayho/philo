# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelahce <abelahce@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/11 15:26:20 by abelahce          #+#    #+#              #
#    Updated: 2022/06/21 14:00:46 by abelahce         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


all: philo

CC=gcc

HEADER=philo.h

UTILS=utils.o

CFLAGS=-Wall -Wextra -Werror -g

NAME=philo

SRC := utils.c	\
		ft_strlen.c	\
		parsing.c	\
		ft_atoi.c	\
		ft_isdigit.c	\

OBJ := $(SRC:.c=.o)

HDR := philo.h

%.o : %.c $(HDR)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME):$(OBJ)
	$(CC) $(CFLAGS) main.c $(OBJ) -o $(NAME)

clean :
	rm -rf  $(OBJ)

fclean: clean
	rm -rf philo

re: fclean all

