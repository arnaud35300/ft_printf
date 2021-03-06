/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 19:22:14 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/30 17:29:22 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Check if a character is a flag.
**
** @param	c	=> the character will be compared with flag list.
**
** @return	boolean value.
*/

t_bool	is_flag(char c)
{
	return (c == '0' || c == '-');
}
