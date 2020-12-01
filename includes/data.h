/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 00:02:38 by arguilla          #+#    #+#             */
/*   Updated: 2020/12/02 00:30:08 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

/*
** Enums.
*/

enum	e_type
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
** Printf structures.
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
** Custom types.
*/

typedef int					t_bool;
typedef unsigned long int	t_ulong;
typedef unsigned int		t_uint;
typedef	t_bool	(t_func)(t_printf *pf, va_list *ap);

#endif
