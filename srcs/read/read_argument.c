/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_argument.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 08:17:25 by arguilla          #+#    #+#             */
/*   Updated: 2020/12/01 19:55:07 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Check against the i position if the next characters are available to form
** a valid argument.
**
** @param	pf	=> the printf structure which contains the string to traveling.
** @param	ap	=> the ap structure which contains the list of arguments.
** @param	i	=> the current index which allows to traveling str.
**
** @return	boolean value, EXIT_ERROR if malloc fails.
*/

t_bool		read_argument(t_printf *pf, va_list *ap, size_t *i)
{
	size_t j;

	j = *i;
	move_str_index(pf->str[j], "%", &j);
	get_flags(pf->str, &j);
	check_number_or_asterisk(pf->str, &j);
	move_str_index(pf->str[j], ".", &j);
	check_number_or_asterisk(pf->str, &j);
	if (is_specifier(pf->str[j]) && pf->str[j])
	{
		store_argument(pf, ap, i);
		*i = ++j;
		return (dispatch_argument(pf, ap));
	}
	else
		increment(pf, i);
	return (TRUE);
}
