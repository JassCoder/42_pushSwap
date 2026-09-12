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
BONUS_NAME = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I. -Ibonus

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
		benchmark/report_utils.c \
		analysis/is_sorted.c \
		analysis/disorder.c \
		analysis/assign_index.c \
		sorting/small.c \
		sorting/simple.c \
		sorting/medium.c \
		sorting/complex.c \
		sorting/adaptive.c

OBJS = $(SRCS:.c=.o)

BONUS_SRCS =	bonus/checker_bonus.c \
				bonus/checker_read_bonus.c \
				bonus/checker_execute_bonus.c \
				bonus/checker_swap_bonus.c \
				bonus/checker_push_bonus.c \
				bonus/checker_rotate_bonus.c \
				bonus/checker_reverse_bonus.c \
				parsing/parse_args.c \
				parsing/parse_flags.c \
				parsing/parse_utils.c \
				parsing/parse_free.c \
				parsing/validate.c \
				parsing/ft_utils_1.c \
				parsing/ft_split.c \
				stack/stack_init.c \
				stack/stack_utils.c \
				stack/stack_free.c \
				benchmark/operation_count.c \
				analysis/is_sorted.c

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

HEADERS = push_swap.h bonus/push_swap_bonus.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
