/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 11:47:12 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/26 20:57:42 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void	store_space(t_printf *pf, char *output, size_t output_len)
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

static void store_arg(t_printf *pf, char *output)
{
	while (*output)
	{
		if (pf->buffer.index >= BUFFER_SIZE)
			read_and_clean_buffer(&(pf->buffer));
		pf->buffer.buffer[pf->buffer.index] = *output;
		pf->buffer.index++;
		pf->len++;
		output++;
	}
}

void	store_output(t_printf *pf, char *output, size_t output_len, bool order)
{
	if (order == SPACE_BEFORE)
	{
		if (pf->format.width > output_len)
			store_space(pf, output, output_len);
		store_arg(pf, output);
	}
	else if (order == SPACE_AFTER)
	{
		store_arg(pf, output);
		if (pf->format.width > output_len)
			store_space(pf, output, output_len);
	}
}
