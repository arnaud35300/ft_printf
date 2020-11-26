/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 09:24:28 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/26 20:49:17 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void store_char_arg(t_printf *pf, va_list *ap)
{
		if (!(pf->buffer.index < BUFFER_SIZE))
			read_and_clean_buffer(&(pf->buffer));
		pf->buffer.buffer[pf->buffer.index] = va_arg(*ap, int);
		pf->buffer.index++;
}

bool		convert_char(t_printf *pf, va_list *ap)
{
	if (pf->format.flags == '-')
	{
		store_char_arg(pf, ap);
		/*
		if (pf->buffer.index < BUFFER_SIZE)
		{
			pf->buffer.buffer[pf->buffer.index] = va_arg(*ap, int);
			pf->buffer.index++;
		}
		else
		{
			read_and_clean_buffer(&(pf->buffer));
			pf->buffer.buffer[pf->buffer.index] = va_arg(*ap, int);
			pf->buffer.index++;
		}
		*/
		store_output(pf, "", SPACE_AFTER);
	}
	else
	{
		store_output(pf, "", SPACE_BEFORE);
		store_char_arg(pf, ap);
		/*if (pf->buffer.index < BUFFER_SIZE)
		{
			pf->buffer.buffer[pf->buffer.index] = va_arg(*ap, int);
			pf->buffer.index++;
		}
		else
		{
			read_and_clean_buffer(&(pf->buffer));
			pf->buffer.buffer[pf->buffer.index] = va_arg(*ap, int);
			pf->buffer.index++;
		}*/
	}
	return (TRUE);
}