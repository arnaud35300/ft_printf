/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 09:24:28 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/30 21:32:14 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Store a character in the buffer.
**
** @param	pf	=> the printf structure.
** @param	ap	=> the ap structure which contains the list of arguments.
**
 ** @return	void.
*/

static void		store_char_arg(t_printf *pf, va_list *ap)
{
	if (!(pf->buffer.index < BUFFER_SIZE))
		read_and_clean_buffer(&(pf->buffer));
	pf->buffer.buffer[pf->buffer.index] = va_arg(*ap, int);
	pf->buffer.index++;
	pf->len++;
}

/*
** Store the conversion of the current argument in the buffer.
**
** @param	pf	=> the printf structure.
** @param	ap	=> the ap structure which contains the list of arguments.
**
 ** @return	boolean value.
*/

t_bool			convert_char(t_printf *pf, va_list *ap)
{
	if (pf->format.flags == '-')
	{
		store_char_arg(pf, ap);
		store_output(pf, "", 1, SPACE_AFTER);
	}
	else
	{
		store_output(pf, "", 1, SPACE_BEFORE);
		store_char_arg(pf, ap);
	}
	return (TRUE);
}
