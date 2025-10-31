# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imengels <imengels@student.42vienna.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/22 13:50:48 by imengels          #+#    #+#              #
#    Updated: 2025/10/22 13:50:50 by imengels         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC      = cc
CFLAGS  = -Wall -Wextra -Werror -g -lreadline -MP -MMD
NAME    = minishell 

SRCS    = main.c ft_pipeline.c

OBJS    = $(SRCS:.c=.o)
DEPS    = $(OBJS:.o=.d)

LIBFT   = libft/libft.a

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C libft bonus

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C libft clean
	rm -f $(OBJS) $(DEPS)

fclean: clean
	$(MAKE) -C libft fclean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re

