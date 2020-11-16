/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_fmt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 15:54:11 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/16 20:56:44 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool		read_fmt(t_printf *pf, va_list *ap)
{
	size_t	i;

	i = 0;
	while (pf->str[i])
	{
		if (!(pf->buffer.index < BUFFER_SIZE))
		{
			read_buffer(&(pf->buffer));
			clean_buffer(pf->buffer);
		}
		pf->buffer.buffer[pf->buffer.index] = pf->str[i];
		i++;
		pf->buffer.index++;
		pf->len++;
	}
	(void)ap;
	return (1);
}
