/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_printf_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 19:47:06 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/18 18:23:12 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_buffer		*init_buffer_struct(void)
{	
	t_buffer	*buffer;

	buffer = malloc(sizeof(t_buffer));
	if (!buffer)
		return (buffer);
	buffer->index = 0;
	buffer->fd = 1;
	return (buffer);
}

static t_format		*init_format_struct(void)
{	
	t_format	*format;

	format = malloc(sizeof(t_format));
	if (!format)
		return (format);
	format->flags = NO_FLAG;
	format->width = NO_WIDTH;
	format->precision = NO_PRECISION;
	format->precision_width = NO_PREC_WIDTH;
	return (format);
}

t_printf	*init_printf_struct(const char *content)
{
	t_printf	*pf;
	t_buffer	*buffer;
	t_format	*format;

	pf = malloc(sizeof(t_printf));
	buffer = init_buffer_struct();
	format = init_format_struct();
	if (!pf || !buffer || !format)
		return (pf);
	pf->len = 0;
	pf->str = (char *)content;
	pf->buffer = *buffer;
	pf->format = *format;
	free(buffer);
	free(format);
	return (pf);
}
