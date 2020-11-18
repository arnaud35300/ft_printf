/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:45:05 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/18 16:47:59 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
/*
** Functions who store current argument into buffer.
*/
bool		store_argument(t_printf *pf, va_list *ap, size_t *i)
{
	size_t j;

	j = *i;
	move_str_index(pf->str[j], "%", &j);
	pf->format.flags = move_str_index(pf->str[j], "-0", &j);
	pf->format.width = store_number_or_asterisk(pf->str, &j, ap);
	pf->format.precision = move_str_index(pf->str[j], ".", &j);
	pf->format.precision_width = store_number_or_asterisk(pf->str, &j, ap);

	printf("flag : %d\n", pf->format.flags);
	printf("width : %d\n", pf->format.width);
	printf("precision : %d\n", pf->format.precision);
	printf("width : %d\n", pf->format.precision_width);
	return (1);
}