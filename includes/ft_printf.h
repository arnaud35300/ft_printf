/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 09:11:53 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/16 22:17:32 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* 
 ** Include dependencies and librairies
*/

# include "libft.h"
# include <ctype.h>
# include <stdlib.h>
# include <stdarg.h>

/*
 ** Macros
*/

# define STDOUT 1
# define bool int
# define TRUE 1
# define FALSE 0
# define BUFFER_SIZE 200 

# define NO_FLAG 0 
# define NO_WIDTH 0
# define NO_PRECISION 0
# define NO_TYPE NULL
# define EXIT_ERROR -1

/*
 ** Enums
*/

enum e_type
{
	c,
	s,
	p,
	d,
	i,
	u,
	x,
	X,
};

/*
 ** Printf structures
*/

typedef struct		s_buffer
{
	char	buffer[BUFFER_SIZE];
	size_t	index;
	int		fd;
}					t_buffer;

typedef struct		s_format
{
	unsigned int	flags;
	unsigned int	width;
	unsigned int	precision;
	enum e_type		type;
}					t_format;

typedef struct		s_printf
{
	int			len;
	char		*str;
	t_buffer	buffer;
	t_format	format;
}					t_printf;

/*
** Functions prototypes
*/

int			ft_printf(const char *fmt, ...);

// verif
bool		is_flag(char c);

// structures
t_printf	*init_printf_struct(const char *content);
void		free_printf_struct(t_printf *pf);

// parsing
bool		read_fmt(t_printf *pf, va_list *ap);

// buffer
void		clean_buffer(t_buffer *buffer);
void		read_buffer(t_buffer *buffer);

#endif
