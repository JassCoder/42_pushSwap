# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jsingh <jsingh@student.42warsaw.pl>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/08 13:48:53 by jsingh            #+#    #+#              #
#    Updated: 2026/08/08 13:48:53 by jsingh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

FT_PRINTF_DIR = ft_printf
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I$(FT_PRINTF_DIR)
LDFLAGS = -L$(FT_PRINTF_DIR) -lftprintf

SRCS = 	main.c \
		stack_init.c stack_push.c \
		stack_rotate.c stack_reverse_rotate.c \
		stack_utils.c stack_disorder.c \
		ft_utils_1.c

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
		$(CC) main_arg.c $(LDFLAGS) -I$(FT_PRINTF_DIR) -o test_push_swap

.PHONY: all clean fclean re