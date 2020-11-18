/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_number_or_asterisk.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:48:29 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/18 16:49:39 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Functions who check if current character is '*' and increment a counter,
** or increment a counter while current character is a number. This version
** return the current width.
*/
int		store_number_or_asterisk(char *str, size_t *j, va_list *ap)
{
	int width;
	int i;

	width = 0;
	i = 10;
	if (str[*j] == '*' && str[*j])
	{
		(*j)++;
		width = va_arg(*ap, int);
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
