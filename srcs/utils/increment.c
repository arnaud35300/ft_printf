/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increment.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 08:11:13 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/18 08:13:26 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Increment len property of the printf structure and i variable.
**
** @param	pf	=> the printf structure.
** @param	i	=> the i iterator.
**
** @return	void.
*/

void	increment(t_printf *pf, size_t *i)
{
	(*i)++;
	pf->buffer.index++;
	pf->len++;
}
