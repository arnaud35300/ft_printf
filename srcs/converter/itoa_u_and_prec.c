/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_u_and_prec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 08:31:32 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/27 19:38:38 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Calculate the length of a number.
**
** @param	n			=> the number where we want to know its length.
** @param	base_len	=> the base length.
**
** @return	the n length.
*/

static int	get_len(uint n, uint base_len)
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
** Convert unsigned int to string.
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

char		*itoa_u_and_prec(uint n, uint prec, uint base_len)
{
	char	*r;
	char	*base;
	uint	len;

	len = get_len(n, base_len);
	if (prec > len)
		len = prec;
	r = malloc(sizeof(char) * (len + 1));
	base = malloc(sizeof(char) * (base_len + 1));
	if (!base || !r)
		return (free_itoa(base, r));
	ft_memset(r, '0', len);
	ft_strlcpy(base, "0123456789abcdef", base_len + 1);
	r[len] = '\0';
	while (n != 0)
	{
		--len;
		r[len] = base[n % base_len];
		n = n / base_len;
	}
	return (free_itoa(base, r));
}
