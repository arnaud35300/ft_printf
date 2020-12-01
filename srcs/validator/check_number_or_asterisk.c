/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_number_or_asterisk.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:57:37 by arguilla          #+#    #+#             */
/*   Updated: 2020/12/01 20:08:14 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Check if current character is '*' and increment a counter, or increment a
** counter while current character is a number.
**
** @param	str	=> the string contains a number or asterisk.
** @param	j	=> the index which allows to trabeled str.
**
** @return	void.
*/

void	check_number_or_asterisk(char *str, size_t *j)
{
	if (str[*j] == '*' && str[*j])
		(*j)++;
	else if (ft_isdigit(str[*j]))
		while (ft_isdigit(str[*j]) && str[*j])
			(*j)++;
}
