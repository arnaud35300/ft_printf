/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:45:05 by arguilla          #+#    #+#             */
/*   Updated: 2020/12/01 20:03:13 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

/*
** Functions who store current argument into format struct.
*/

bool	store_argument(t_printf *pf, va_list *ap, size_t *i)
{
	size_t	j;

	j = *i;
	move_str_index(pf->str[j], "%", &j);
	pf->format.flags = get_flags(pf->str, &j);
	pf->format.width = store_number_or_asterisk(pf->str, &j, ap, &(pf->format));
	pf->format.precision = move_str_index(pf->str[j], ".", &j);
	pf->format.precision_width = store_number_or_asterisk(pf->str, &j, ap,
								&(pf->format));
	pf->format.type = get_type(pf->str[j]);
	return (TRUE);
}
