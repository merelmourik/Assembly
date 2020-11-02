# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: merelmourik <merelmourik@student.42.fr>      +#+                      #
#                                                    +#+                       #
#    Created: 2020/09/17 14:05:11 by merelmourik   #+#    #+#                  #
#    Updated: 2020/09/29 10:32:50 by merelmourik   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRCS = ft_strcpy.s ft_strlen.s ft_strdup.s ft_strcmp.s ft_read.s ft_write.s
CC = gcc
CFLAGS = -I. -Wall -Werror -Wextra
NAME = libasm.a

OBJ := $(SRCS:.s=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o: %.s
	nasm -f macho64 $< -o $@

.PHONY: clean fclean re all test

clean:
	-rm -f $(OBJ)

fclean: clean
	-rm -f $(NAME)
	-rm -rf a.out.dSYM
	-rm -f a.out test.txt

re: fclean all

run: $(NAME)
	make re
	$(CC) -g -L. -lasm main.c
	./a.out