/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_number_or_asterisk.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:48:29 by arguilla          #+#    #+#             */
/*   Updated: 2020/12/01 20:01:59 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Converts a number by its reverse sign, and assign the flag '-'
**
** @param	width	=> the number to be converted.
** @param 	format	=> the format structure which contains flag property.
**
** @return	void.
*/

static void		assign_width(int *width, t_format *format)
{
	*width *= (-1);
	format->flags = '-';
}

static void		clean_precision(t_format *format)
{
	format->precision = NO_PRECISION;
	format->precision_width = NO_PREC_WIDTH;
}

/*
** Equivalents to atoi function with variable incrementation.
**
** @param	c		=> the current character will be converted to int.
** @param	width	=> the string where the c conversion is stored.
** @param	i		=> the i counter is increment, and it allows to check
** that the number stored in the width string will not exceed the maximum
** length of an int.
** @param	j		=> the j counter is increment, and it allows to browse
** string str which is an argument of the previous function.
**
** @return	void.
*/

static void		width_atoi(char c, int *width, int *i, size_t *j)
{
	*width = *width * 10 + c - 48;
	(*j)++;
	(*i)--;
}

/*
** Iterate over the str string to retrieve a number.
**
** @param	str		=> the string traveled.
** @param	j		=> the current index which allows to traveling str.
** @param	ap		=> the ap structure which contains the list of arguments.
** @param	format	=> the format structure.
**
** @return	the number retrieved by browsing the string or through the list
** of arguments of ap.
*/

int				store_number_or_asterisk(char *str, size_t *j,
				va_list *ap, t_format *format)
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
			else if (str[*j - 1] == FMT_META_CHAR || format->flags == '0')
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
