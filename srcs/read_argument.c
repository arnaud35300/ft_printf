/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_argument.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 08:17:25 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/30 20:59:29 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>

/*
static void	store_percent(t_printf *pf, size_t *i, size_t *j)
{
	*i = ++(*j);
	if (!(pf->buffer.index < BUFFER_SIZE))
		read_and_clean_buffer(&(pf->buffer));
	pf->buffer.buffer[pf->buffer.index] = '%';
	pf->buffer.index++;
	pf->len++;
}*/

/*
** Functions who take the current position to argument in fmt, and check if
** this argument is valid and return a boolean.
*/
bool		read_argument(t_printf *pf, va_list *ap, size_t *i)
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
		return (dispatch_argument(pf, ap, i));
	}
	else
		increment(pf, i);
	return (TRUE);
}
