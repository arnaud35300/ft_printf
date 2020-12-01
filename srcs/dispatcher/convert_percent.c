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

bool		convert_percent(t_printf *pf, va_list *ap)
{
	(void)ap;
	if (pf->buffer.index >= BUFFER_SIZE)
		read_and_clean_buffer(&(pf->buffer));
	pf->buffer.buffer[pf->buffer.index] = '%';
	pf->buffer.index++;
	pf->len++;
	return (TRUE);
}
