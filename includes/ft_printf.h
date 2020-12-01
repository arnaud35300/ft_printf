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
** Include dependencies and librairies.
*/

# include "libft.h"
# include <limits.h>
# include <ctype.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>

/*
** Macros.
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
** Functions prototypes.
*/

# include "data.h"
# include "free.h"
# include "store.h"
# include "validator.h"
# include "getter.h"
# include "read.h"
# include "dispatcher.h"
# include "clean.h"
# include "utils.h"
# include "converter.h"

int			ft_printf(const char *fmt, ...);

#endif
