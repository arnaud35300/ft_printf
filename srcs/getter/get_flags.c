/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 17:41:33 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/30 17:58:09 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** browse flags into a string and return them.
**
** @param	str	=> the str will be traveled to find flags.
** @param	j	=>  the current position into str.
**
** @return	flag, '\0' if there is no match.
*/

char	get_flags(char *str, size_t *j)
{
	t_bool is_neg;
	t_bool is_zero;

	is_zero = FALSE;
	is_neg = FALSE;
	while (is_flag(str[*j]) && str[*j])
	{
		if (str[*j] == '-')
			is_neg = TRUE;
		if (str[*j] == '0')
			is_zero = TRUE;
		(*j)++;
	}
	if (is_neg == TRUE)
		return ('-');
	if (is_zero == TRUE)
		return ('0');
	return (NO_FLAG);
}
