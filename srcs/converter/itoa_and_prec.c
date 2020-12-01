/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_and_prec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:18:58 by arguilla          #+#    #+#             */
/*   Updated: 2020/12/01 16:53:28 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Give the absolute vaule of a number
**
** @param	n	=> the number where we want to know its absolute value.
**
** @return	the absolute value of n.
*/

static long		get_absolute(long n)
{
	if (n > 0)
		return (n);
	return (-n);
}

/*
** Calculate the length of a number.
**
** @param	n			=> the number where we want to know its length.
** @param	base_len	=> the base length.
**
** @return	the n length.
*/

static uint		get_len(long n, long base_len)
{
	uint	len;

	len = 0;
	if (n <= 0)
		++len;
	while (n != 0)
	{
		n = n / base_len;
		len++;
	}
	return (len);
}

/*
** Adjust the width precision if the number is negative.
**
** @param	n		=> the number to be converted.
** @param	prec	=> the width precision.
** @param	is_prec	=> specifier which allows to interpreted the precision
** differently.
**
** @return	the new width precision.
*/

static uint		get_prec(long n, uint prec, bool is_prec)
{
	if (n < 0 && is_prec)
		return (++prec);
	return (prec);
}

/*
** Convert long to string.
**
** @param	n		 	=> the number to be converted.
** @param	prec	 	=> the precision width.
** @param	base_len	=> the length of the base to which the number
** should be converted.
** @param	is_prec		=> specifier that allows to know if the variable
** prec is the width of a flag '0' or of a precision '.', both reacting
** differently.
**
** @return	a string representing the conversion of the number, NULL
** if malloc fails.
*/

char			*itoa_and_prec(long n, uint prec, long base_len, bool is_prec)
{
	char	*r;
	char	*base;
	uint	len;

	len = get_len(n, base_len);
	if ((prec > len) || (n < 0 && prec >= len && is_prec))
		len = get_prec(n, prec, is_prec);
	r = malloc(sizeof(char) * (len + 1));
	base = malloc(sizeof(char) * (base_len + 1));
	if (!base || !r)
		return (free_itoa(base, r));
	ft_memset(r, '0', len);
	ft_strlcpy(base, "0123456789abcdef", base_len + 1);
	r[len] = '\0';
	if (n < 0)
		r[0] = '-';
	while (n != 0)
	{
		--len;
		r[len] = base[get_absolute(n) % base_len];
		n = n / base_len;
	}
	return (free_itoa(base, r));
}
