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
** Store values in the properties of the format structure.
**
** @param	pf	=> the printf structure which contains the format structure.
** @param	ap	=> the ap structure which contains the list of arguments.
** @param	i	=> the current index which allows to traveling str.
**
** @return	boolean value, EXIT_ERROR if malloc fails.
*/

t_bool	store_argument(t_printf *pf, va_list *ap, size_t *i)
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
