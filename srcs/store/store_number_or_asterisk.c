/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_number_or_asterisk.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:48:29 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/29 23:33:36 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	assign_width(int *width, t_format *format)
{
	*width *= (-1);
	format->flags = '-';
}

static void clean_precision(t_format *format)
{
	format->precision = NO_PRECISION;
	format->precision_width = NO_PREC_WIDTH;
}

static void width_atoi(char c, int *width, int *i, size_t *j)
{
	*width = *width * 10 + c - 48;
	(*j)++;
	(*i)--;
}

/*
** Functions who check if current character is '*' and increment a counter,
** or increment a counter while current character is a number. This version
** return the current width.
*/
int		store_number_or_asterisk(char *str, size_t *j, va_list *ap, t_format *format)
{
	int width;
	int i;
	
	width = 0;
	i = 10;
	if (str[*j] == '*' && str[*j])
	{
		width = va_arg(*ap, int);
		if (width < 0)
		{
			if (str[*j - 1] == '.')
				clean_precision(format);
			else if(str[*j - 1] == FMT_META_CHAR || format->flags == '0')
				assign_width(&width, format);
			else
				width *= (-1);
		}
		(*j)++;
	}
	else if (ft_isdigit(str[*j]))
		while (ft_isdigit(str[*j]) && str[*j] && i)
			width_atoi(str[*j], &width, &i, j);
	return (width);
}
