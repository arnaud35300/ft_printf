/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_lu_and_prec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 15:07:23 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/29 15:34:01 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_len(long unsigned int n, long unsigned int base_len)
{
	long unsigned int	len;

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

char	*itoa_lu_and_prec(long unsigned int n, long unsigned int prec, long unsigned int base_len)
{
	char			*r;
	char			*base;
	long unsigned int	len;
	
	len = get_len(n, base_len) + 2;
	if (prec > len)
		len = prec + 2;
	r = malloc(sizeof(char) * (len + 1));
	base = malloc(sizeof(char) * (base_len + 1));
	if (!base || !r)
		return (free_itoa(base, r));
	ft_memset(r, '0', len);
	r[1] = 'x';
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
