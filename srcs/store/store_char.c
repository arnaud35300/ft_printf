/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 08:18:05 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/18 08:21:41 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Store a character in the buffer.
**
** @param	pf	=> the printf structure which contains the buffer structure.
** @param	i	=> the current index which allows to traveling str.
**
** @return	void.
*/

void		store_char(t_printf *pf, size_t *i)
{
	pf->buffer.buffer[pf->buffer.index] = pf->str[*i];
	increment(pf, i);
}
