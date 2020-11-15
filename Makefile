# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arguilla <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/11 08:48:33 by arguilla          #+#    #+#              #
#    Updated: 2020/11/11 19:48:44 by arguilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# [ VARIABLES ] #

NAME		= libftprintf.a
RM			= rm -rf
MAKE		= make
LIBFT		= libft

# [ COMPILATION VARIABLES ] #

CC			= gcc
CFLAGS		= -c -Wall -Wextra -Werror

# [ OBJECTS ] #

OBJS		= ft_printf.o

# [ PATH ] #

VPATH		= includes:srcs

# [ RULES ] #

all:		$(NAME)

%.o : %.c
			@$(CC) $(CFLAGS) -I./includes -I./libft $< -o $@

$(NAME):	$(OBJS)
			@$(MAKE) -C $(LIBFT)
			@ar rc $(NAME) $(OBJS)
			@ranlib $(NAME)	

clean:
			@$(RM) $(OBJS) 2>/dev/null
			@$(MAKE) clean -C $(LIBFT)

fclean:		clean
			@$(RM) $(NAME) 2>/dev/null
			@$(MAKE) fclean -C $(LIBFT)

re:			fclean all

.PHONY:		all clean re fclean
