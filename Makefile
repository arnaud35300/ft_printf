# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arguilla <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/11 08:48:33 by arguilla          #+#    #+#              #
#    Updated: 2020/11/30 20:16:24 by arguilla         ###   ########.fr        #
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

OBJS		= ft_printf.o\
			  assign_output.o\
			  assign_output_p.o\
			  assign_output_u.o\
			  assign_tab_converter.o\
			  check_number_or_asterisk.o\
			  clean_buffer.o\
			  clean_flag_and_precision.o\
			  convert_char.o\
			  convert_d_int.o\
			  convert_hex_l.o\
			  convert_hex_u.o\
			  convert_i_int.o\
			  convert_ptr.o\
			  convert_str.o\
			  convert_u_int.o\
			  dispatch_argument.o\
			  free_printf_struct.o\
			  get_argument_len.o\
			  get_type.o\
			  increment.o\
			  init_printf_struct.o\
			  is_flag.o\
			  is_negative.o\
			  is_specifier.o\
			  itoa_and_prec.o\
			  itoa_lu_and_prec.o\
			  itoa_u_and_prec.o\
			  move_str_index.o\
			  read_and_clean_buffer.o\
			  read_argument.o\
			  read_buffer.o\
			  read_fmt.o\
			  store_argument.o\
			  store_char.o\
			  store_number_or_asterisk.o\
			  store_output.o\
			  get_flags.o\
			  convert_percent.o\
			  free_output.o\
			  free_itoa.o

# [ PATH ] #

VPATH		= includes:srcs:srcs/free:srcs/store:srcs/validator:srcs/getter:srcs/read:srcs/dispatcher:srcs/utils:srcs/clean:srcs/converter

# [ RULES ] #

all:		$(NAME)

%.o : %.c
			@$(CC) $(CFLAGS) -I./includes -I./libft -I./srcs/free -I./srcs/store -I./srcs/validator -I./srcs/getter -I./srcs/read -I./srcs/dispatcher -I./srcs/utils -I./srcs/clean -I./srcs/converter $< -o $@

$(NAME):	$(OBJS)
			@$(MAKE) -C $(LIBFT)
			cp libft/libft.a  $(NAME)
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
