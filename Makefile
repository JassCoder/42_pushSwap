# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsingh <jsingh@student.42warsaw.pl>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/28 10:40:28 by jsingh            #+#    #+#              #
#    Updated: 2026/08/28 10:40:28 by jsingh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I.

SRCS =	main.c \
		parsing/parse_args.c \
		parsing/parse_flags.c \
		parsing/parse_utils.c \
		parsing/parse_free.c \
		parsing/validate.c \
		parsing/ft_utils_1.c \
		stack/stack_init.c \
		stack/stack_utils.c \
		stack/stack_free.c \
		parsing/ft_split.c \
		operations/swap.c \
		operations/push.c \
		operations/rotate.c \
		operations/reverse_rotate.c \
		benchmark/operation_count.c \
		benchmark/report.c \
		analysis/is_sorted.c \
		analysis/disorder.c \
		analysis/assign_index.c \
		sorting/simple.c \
		sorting/medium.c \
		sorting/complex.c \
		sorting/adaptive.c \

OBJS = $(SRCS:.c=.o)

HEADERS = push_swap.h

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADERS)
		$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

test:
		$(CC) $(CFLAGS) $(INCLUDES) main.c -o test_push_swap

.PHONY: all clean fclean re