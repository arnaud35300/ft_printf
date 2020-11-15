/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 09:11:53 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/14 20:17:40 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
 ** MACROS
*/

# define STDOUT 1
# define bool int
# define TRUE 1
# define FALSE 0

/*
 ** FLAG STRUCTURE 
*/

typedef struct		s_arg
{
	bool	flag_negative;
	bool	flag_zero;
	bool	flag_star;
	bool	precision;
	int		precision_width;
	int		width;
	char	type;
}					t_arg;

/* 
 ** Include dependencies (libft)
*/

# include "libft.h"
# include <stdarg.h>

/*
** Functions prototypes
*/

int		ft_printf(const char *fmt, ...);
int		check_arg(const char *arg);
void	display_arg(const char *arg);
bool	is_flag(char c);
t_arg	*init_struct(void);
void	assign_flag(t_arg *arg_control, char flag);

#endif
