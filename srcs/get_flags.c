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

char	get_flags(char *str, size_t *j)
{
	bool is_neg;
	bool is_zero;

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
