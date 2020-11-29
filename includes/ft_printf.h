/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 09:11:53 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/29 15:16:55 by arguilla         ###   ########.fr       */
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

/*
** Types and flags
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

# define STDOUT				1
# define bool				int
# define TRUE				1
# define FALSE				0
# define BUFFER_SIZE		1 

# define NO_FLAG			'\0' 
# define NO_WIDTH			0
# define NO_PRECISION		'\0'
# define NO_PREC_WIDTH		0
# define NO_TYPE			-1
# define EXIT_ERROR			-1
# define SPECIFIER_COUNT	8
# define NB_SIZE			11
# define SPACE_BEFORE		1
# define SPACE_AFTER		2
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


/*
** Functions prototypes
*/

int			ft_printf(const char *fmt, ...);


// structures
t_printf	*init_printf_struct(const char *content);
void		free_printf_struct(t_printf *pf);

// parsing
bool		read_fmt(t_printf *pf, va_list *ap);
void		store_char(t_printf *pf, size_t *i);
bool		read_argument(t_printf *pf, va_list *ap, size_t *i);

// store
bool		store_argument(t_printf *pf, va_list *ap, size_t *i);
int			store_number_or_asterisk(char *str, size_t *j, va_list *ap, t_format *format);
char		move_str_index(char c, char *compare, size_t *j);
void		check_number_or_asterisk(char *str, size_t *j);
void		store_output(t_printf *pf, char *output, size_t output_len, bool order);

// dispatch
bool	dispatch_argument(t_printf *pf, va_list *ap, size_t *i);

// validator
bool		is_flag(char c);
bool		is_specifier(char c);
bool		is_negative(int *nb);

// getter
int			get_type(char c);

// buffer
void		clean_buffer(t_buffer *buffer);
void		read_buffer(t_buffer *buffer);
void		read_and_clean_buffer(t_buffer *buffer);

// utils
void		increment(t_printf *pf, size_t *i);
void		clean_flag_and_precision(t_format *format);
size_t		get_argument_len(t_format *format, char *output);

// convertion
bool		convert_char(t_printf *pf, va_list *ap);
bool		convert_str(t_printf *pf, va_list *ap);
bool		convert_ptr(t_printf *pf, va_list *ap);
bool		convert_d_int(t_printf *pf, va_list *ap);
bool		convert_i_int(t_printf *pf, va_list *ap);
bool		convert_u_int(t_printf *pf, va_list *ap);
bool		convert_hex_l(t_printf *pf, va_list *ap);
bool		convert_hex_u(t_printf *pf, va_list *ap);

char		*assign_output(t_format *format, int nb);
char		*assign_output_u(t_format *format, unsigned int nb);
char		*assign_output_p(t_format *format, void *nb);
char		*itoa_and_prec(int n, unsigned int prec, int base_len);
char		*itoa_u_and_prec(unsigned int n, unsigned int prec, unsigned int base_len);
char		*itoa_lu_and_prec(long unsigned int n, long unsigned int prec, long unsigned int base_len);
// functions tab
typedef bool	t_func(t_printf *pf, va_list *ap);
void		assign_tab_converter(t_func **tab);

#endif
