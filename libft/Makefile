# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imengels <imengels@student.42vienna.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/22 13:51:20 by imengels          #+#    #+#              #
#    Updated: 2025/10/22 13:51:22 by imengels         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -std=c90 -MMD -MP
NAME = libft.a
BONUS_SRCS = bonus/ft_lstadd_front_bonus.c bonus/ft_lstmap_bonus.c bonus/ft_lstiter_bonus.c bonus/ft_lstclear_bonus.c bonus/ft_lstnew_bonus.c \
	bonus/ft_lstdelone_bonus.c bonus/ft_lstadd_back_bonus.c bonus/ft_lstlast_bonus.c bonus/ft_lstsize_bonus.c \
	bonus/ft_dlstclear_bonus.c bonus/ft_dlstdelone_bonus.c bonus/ft_dlstnew_bonus.c bonus/ft_dlstadd_back_bonus.c \
	bonus/ft_dlstlast_bonus.c bonus/ft_dlst_unwrap_bonus.c bonus/ft_dlstadd_after.c
SRCS = srcs/ft_atoi.c srcs/ft_bzero.c srcs/ft_calloc.c srcs/ft_isalnum.c srcs/ft_isalpha.c \
	srcs/ft_isascii.c srcs/ft_isdigit.c srcs/ft_isprint.c srcs/ft_memchr.c srcs/ft_memcmp.c \
	srcs/ft_memcpy.c srcs/ft_memmove.c srcs/ft_memset.c srcs/ft_strchr.c srcs/ft_strdup.c \
	srcs/ft_strlcat.c srcs/ft_strlcpy.c srcs/ft_strlen.c srcs/ft_strncmp.c srcs/ft_strnstr.c \
	srcs/ft_strrchr.c srcs/ft_tolower.c srcs/ft_toupper.c srcs/ft_strjoin.c srcs/ft_substr.c \
	srcs/ft_strtrim.c srcs/ft_split.c srcs/ft_itoa.c srcs/ft_strmapi.c srcs/ft_striteri.c \
	srcs/ft_putchar_fd.c srcs/ft_putnbr_fd.c srcs/ft_putstr_fd.c srcs/ft_putendl_fd.c \
	limit/ft_limit_int_ll.c limit/ft_limit_short_sst.c limit/ft_limit_unsigned.c srcs/ft_table.c \
	srcs/ft_free_null.c srcs/ft_arr.c srcs/ft_str_f.c srcs/ft_arr_f.c srcs/ft_str_checks.c \
	srcs/ft_insertsubstr.c srcs/ft_delsubstr.c \
	srcs/ft_arr_checks.c srcs/ft_isspace.c gnl/get_next_line.c gnl/get_next_line_utils.c
BONUS_OBJS      = $(BONUS_SRCS:.c=.o)
BONUS_DEPS	= $(BONUS_OBJS:.o=.d) 
OBJS    = $(SRCS:.c=.o)
DEPS	= $(OBJS:.o=.d) 


ifeq ($(firstword $(MAKECMDGOALS)),bonus)
ALL_OBJS := $(OBJS) $(BONUS_OBJS)
else
ALL_OBJS := $(OBJS)
endif

$(NAME): $(ALL_OBJS)
	ar rcs $@ $(ALL_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	rm -f $(OBJS) $(BONUS_OBJS) $(DEPS) $(BONUS_DEPS)

fclean:	 clean
	rm -f $(NAME)

re: fclean all

bonus: $(NAME)

.PHONY: all bonus clean fclean re

-include $(DEPS) $(BONUS_DEPS)
