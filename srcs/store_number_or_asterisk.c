/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_number_or_asterisk.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:48:29 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/26 10:32:16 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	assign_width(int *width, t_format *format)
{
	*width *= (-1);
	format->flags = '-';
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
			if (str[*j -1] == '.')
				width = 0;
			else if(str[*j - 1] == FMT_META_CHAR)
				assign_width(&width, format);
			else
				width *= (-1);
		(*j)++;
	}
	else if (ft_isdigit(str[*j]))
		while (ft_isdigit(str[*j]) && str[*j] && i)
		{
			width = width * 10 + str[*j] - 48;
			(*j)++;
			i--;
		}
	return (width);
}
