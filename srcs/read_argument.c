/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_argument.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 08:17:25 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/18 16:59:24 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Functions who take the current position to argument in fmt, and check if
** this argument is valid and return a boolean.
*/
bool		read_argument(t_printf *pf, va_list *ap, size_t *i)
{
	size_t j;

	j = *i;
	move_str_index(pf->str[j], "%", &j);
	move_str_index(pf->str[j], "-0", &j);
	check_number_or_asterisk(pf->str, &j);
	move_str_index(pf->str[j], ".", &j);
	check_number_or_asterisk(pf->str, &j);
	if (is_specifier(pf->str[j]) && pf->str[j])
	{
		store_argument(pf, ap, i);
		*i += ++j;
	}
	else
		increment(pf, i);
	return (1);
}
