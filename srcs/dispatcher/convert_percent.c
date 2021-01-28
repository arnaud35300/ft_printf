/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 18:12:13 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/30 21:02:04 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		store_in_buffer(t_printf *pf, char c)
{
	if (pf->buffer.index >= BUFFER_SIZE)
		read_and_clean_buffer(&(pf->buffer));
	pf->buffer.buffer[pf->buffer.index] = c;
	pf->buffer.index++;
	pf->len++;
}

static void		store_char_arg(t_printf *pf)
{
	if (pf->format.flags == '0')
	{
		while (pf->format.width > 1)
		{
			store_in_buffer(pf, '0');
			pf->format.width--;
		}
	}
	store_in_buffer(pf, '%');
}

/*
** Store the conversion of the current argument in the buffer.
**
** @param	pf	=> the printf structure.
** @param	ap	=> the ap structure which contains the list of arguments.
**
 ** @return	boolean value.
*/

t_bool			convert_percent(t_printf *pf, va_list *ap)
{
	(void)ap;
	if (pf->format.flags == '-')
	{
		store_char_arg(pf);
		store_output(pf, "", 1, SPACE_AFTER);
	}
	else if (pf->format.flags == '0')
	{
		store_char_arg(pf);
		store_output(pf, "", 1, SPACE_AFTER);
	}
	else
	{
		store_output(pf, "", 1, SPACE_BEFORE);
		store_char_arg(pf);
	}
	return (TRUE);
}
