/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 11:47:12 by arguilla          #+#    #+#             */
/*   Updated: 2020/12/01 20:05:36 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Store spaces in the buffer.
**
** @param	pf 			=> the printf structure which contains
** the buffer structure.
** @param	output_len	=> the output length will be compared with width to
** determine the number of spaces to store.
**
 ** @return	void.
*/

static void		store_space(t_printf *pf, size_t output_len)
{
	while (pf->format.width > output_len)
	{
		if (pf->buffer.index >= BUFFER_SIZE)
			read_and_clean_buffer(&(pf->buffer));
		pf->buffer.buffer[pf->buffer.index] = ' ';
		pf->format.width--;
		pf->buffer.index++;
		pf->len++;
	}
}

/*
** Store output value in the buffer.
**
** @param	pf 		=> the printf structure which contains
** the buffer structure.
** @param	output	=> the string to be stored in the buffer.
**
 ** @return	void.
*/

static void		store_arg(t_printf *pf, char *output)
{
	while (*output)
	{
		if (pf->buffer.index >= BUFFER_SIZE)
			read_and_clean_buffer(&(pf->buffer));
		if (pf->format.type == X)
			pf->buffer.buffer[pf->buffer.index] = ft_toupper(*output);
		else
			pf->buffer.buffer[pf->buffer.index] = *output;
		pf->buffer.index++;
		pf->len++;
		output++;
	}
}

/*
** Store output value with his width in the buffer.
**
** @param	pf 			=> the printf structure which contains
** the buffer structure.
** @param	output		=> the string to be stored in the buffer.
** @param	output_len	=> the output length.
** @param	order		=> the order in which the spaces will be
** stored relative to the string.
**
 ** @return	void.
*/

void			store_output(t_printf *pf, char *output,
				size_t output_len, bool order)
{
	if (order == SPACE_BEFORE)
	{
		if (pf->format.width > output_len)
			store_space(pf, output_len);
		store_arg(pf, output);
	}
	else if (order == SPACE_AFTER)
	{
		store_arg(pf, output);
		if (pf->format.width > output_len)
			store_space(pf, output_len);
	}
}
