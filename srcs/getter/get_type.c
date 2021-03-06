/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 08:20:38 by arguilla          #+#    #+#             */
/*   Updated: 2020/12/01 19:54:44 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** give the type by comparing the character with the list of types.
**
** @param	c => the character to compare.
**
** @return	match index.
*/

int		get_type(char c)
{
	int	i;

	i = -1;
	if (FMT_CHAR == c)
		i = 0;
	if (FMT_STR == c)
		i = 1;
	if (FMT_PTR == c)
		i = 2;
	if (FMT_D_INT == c)
		i = 3;
	if (FMT_I_INT == c)
		i = 4;
	if (FMT_U_INT == c)
		i = 5;
	if (FMT_HEX_L == c)
		i = 6;
	if (FMT_HEX_U == c)
		i = 7;
	if (FMT_META_CHAR == c)
		i = 8;
	return (i);
}
