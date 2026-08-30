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

FT_PRINTF_DIR = ft_printf
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I. -I$(FT_PRINTF_DIR)
LDFLAGS = -L$(FT_PRINTF_DIR) -lftprintf

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
		analysis/is_sorted.c \
		analysis/disorder.c \
		analysis/assign_index.c \
		sorting/simple.c \
		sorting/medium.c \
		sorting/complex.c \
		sorting/adaptive.c \

OBJS = $(SRCS:.c=.o)

HEADERS = push_swap.h

all: $(FT_PRINTF_LIB) $(NAME)

$(FT_PRINTF_LIB):
			make -C $(FT_PRINTF_DIR)

$(NAME): $(OBJS) $(FT_PRINTF_LIB)
		$(CC) $(CFLAGS) $(OBJS) $(FT_PRINTF_LIB) $(LDFLAGS) -o $(NAME)

%.o: %.c $(HEADERS)
		$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean: 
		make -C $(FT_PRINTF_DIR) clean
		rm -f $(OBJS)

fclean: clean
		make -C $(FT_PRINTF_DIR) fclean
		rm -f $(NAME)

re: fclean all

test: $(FT_PRINTF_LIB)
		$(CC) main.c $(LDFLAGS) -I$(FT_PRINTF_DIR) -o test_push_swap

.PHONY: all clean fclean re