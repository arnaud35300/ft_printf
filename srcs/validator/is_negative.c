/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_negative.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 08:39:50 by arguilla          #+#    #+#             */
/*   Updated: 2020/12/01 20:08:35 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Check if a number is negative, and if the number is negative, convert it
** to positive number.
**
** @param	nb	=> the number to test.
**
** @return	boolean value.
*/

t_bool	is_negative(int *nb)
{
	if (*nb < 0)
	{
		*nb = *nb * (-1);
		return (TRUE);
	}
	return (FALSE);
}
