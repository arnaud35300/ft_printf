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
** Functions who check if a character is into a string
** and increments the second argument
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
