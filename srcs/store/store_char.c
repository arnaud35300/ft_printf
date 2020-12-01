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

void		store_char(t_printf *pf, size_t *i)
{
	pf->buffer.buffer[pf->buffer.index] = pf->str[*i];
	increment(pf, i);
}
