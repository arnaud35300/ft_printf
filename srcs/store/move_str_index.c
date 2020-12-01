/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_str_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:50:26 by arguilla          #+#    #+#             */
/*   Updated: 2020/12/01 20:07:33 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Compare a character with a string and give the character that matches.
**
** @param	c 		=> the character to compare.
** @param	compare	=> the string where will compare the character c.
** @param	j		=> the current index which allows to traveling str.
**
** @return	c if is into compare string, '\0' otherwise.
*/

char	move_str_index(char c, char *compare, size_t *j)
{
	while (*compare)
	{
		if (c == *compare && c)
		{
			(*j)++;
			return (c);
		}
		compare++;
	}
	return ('\0');
}
