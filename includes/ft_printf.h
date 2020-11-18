/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 09:11:53 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/18 17:02:02 by arguilla         ###   ########.fr       */
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

/*
** Types and flags
*/

# define FMT_META_CHAR		'%'
# define FMT_CHAR			'c'
# define FMT_STR			's'
# define FMT_PTR			'c'
# define FMT_D_INT			'd'
# define FMT_I_INT			'i'
# define FMT_U_INT			'u'
# define FMT_HEX_L			'x'
# define FMT_HEX_U			'X'

# define STDOUT				1
# define bool				int
# define TRUE				1
# define FALSE				0
# define BUFFER_SIZE		1 

# define NO_FLAG			'\0' 
# define NO_WIDTH			0
# define NO_PRECISION		'\0'
# define NO_PREC_WIDTH		0
# define NO_TYPE			NULL
# define EXIT_ERROR			-1
# define SPECIFIER_COUNT	8
# define NB_SIZE			11 
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
void		store_char(t_printf *pf, size_t *i);
bool		read_argument(t_printf *pf, va_list *ap, size_t *i);

// store
bool		store_argument(t_printf *pf, va_list *ap, size_t *i);
int			store_number_or_asterisk(char *str, size_t *j, va_list *ap);
char		move_str_index(char c, char *compare, size_t *j);
void		check_number_or_asterisk(char *str, size_t *j);

// validator
bool		is_specifier(char c);
// buffer
void		clean_buffer(t_buffer *buffer);
void		read_buffer(t_buffer *buffer);
void		read_and_clean_buffer(t_buffer *buffer);

// utils
void	increment(t_printf *pf, size_t *i);

#endif
