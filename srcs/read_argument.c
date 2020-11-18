/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_argument.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 08:17:25 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/18 15:03:32 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

/*
** Functions who check if a character is in string and increments the second argument
*/
static void		move_str_index(char c, char *compare, size_t *j)
{
	while (*compare)
	{
		if (c == *compare && c)
		{
			(*j)++;
			return ;
		}
		compare++;
	}
}

/*
** Functions who check if current character is '*' and increment a counter,
** or increment a counter while current character is a number.
*/
static void		check_number_or_asterisk(char *str, size_t *j)
{
	if (str[*j] == '*' && str[*j])
		(*j)++;
	else if (ft_isdigit(str[*j]))
		while (ft_isdigit(str[*j]) && str[*j])
			(*j)++;
}

/*
** Functions who take the current position to argument in fmt, and check if
** this argument is valid and return a boolean.
*/

//bool		store_argument
bool		read_argument(t_printf *pf, va_list *ap, size_t *i)
{
	size_t j;

	j = *i;
	move_str_index(pf->str[j], "%", &j);
	move_str_index(pf->str[j], "-0", &j);
	check_number_or_asterisk(pf->str, &j);
	move_str_index(pf->str[j], ".", &j);
	check_number_or_asterisk(pf->str, &j);
	if (is_specifier(pf->str[j]) && pf->str[j])
	{
		//store_argument(pf, ap, i);
		*i += ++j;
	}
	else
		increment(pf, i);
	(void)pf;
	(void)ap;
	return (1);
}
