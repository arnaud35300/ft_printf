/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_fmt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 15:54:11 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/18 17:49:05 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool		read_fmt(t_printf *pf, va_list *ap)
{
	size_t	i;

	i = 0;
	clean_buffer(&(pf->buffer));
	while (pf->str[i])
	{
		if (pf->buffer.index >= BUFFER_SIZE)
			read_and_clean_buffer(&(pf->buffer));
		if (pf->str[i] == FMT_META_CHAR)
		{
			//write(1,"yo", 2);
			read_argument(pf, ap, &i);
		}
		else
			store_char(pf, &i);
	}
	read_and_clean_buffer(&(pf->buffer));
	return (1);
}
