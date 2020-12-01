/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 09:11:53 by arguilla          #+#    #+#             */
/*   Updated: 2020/12/01 19:36:11 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* 
 ** Include dependencies and librairies
*/

# include "libft.h"
# include <limits.h>
# include <ctype.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>

/*
 ** Macros
*/

# define FMT_META_CHAR		'%'
# define FMT_CHAR			'c'
# define FMT_STR			's'
# define FMT_PTR			'p'
# define FMT_D_INT			'd'
# define FMT_I_INT			'i'
# define FMT_U_INT			'u'
# define FMT_HEX_L			'x'
# define FMT_HEX_U			'X'
# define bool				int
# define TRUE				1
# define FALSE				0
# define BUFFER_SIZE		40 
# define NO_FLAG			'\0' 
# define NO_WIDTH			0
# define NO_PRECISION		'\0'
# define NO_PREC_WIDTH		0
# define NO_TYPE			-1
# define EXIT_ERROR			-1
# define SPACE_BEFORE		1
# define SPACE_AFTER		2

/*
 ** Macros types
*/

# define ulong				unsigned long int
# define uint				unsigned int

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
	pc,
};

/*
 ** Printf structures
*/

typedef struct		s_buffer
{
	size_t	index;
	int		fd;
	char	buffer[BUFFER_SIZE];
}					t_buffer;

typedef struct		s_format
{
	unsigned int	flags;
	unsigned int	width;
	unsigned int	precision;
	unsigned int	precision_width;
	enum e_type		type;
}					t_format;

typedef struct		s_printf
{
	int			len;
	char		*str;
	t_buffer	buffer;
	t_format	format;
}					t_printf;

typedef bool	t_func(t_printf *pf, va_list *ap);

/*
** Functions prototypes
*/
int			ft_printf(const char *fmt, ...);

# include "free.h"
# include "store.h"
# include "validator.h"
# include "getter.h"
# include "read.h"
# include "dispatcher.h"
# include "clean.h"
# include "utils.h"
# include "converter.h"

#endif
