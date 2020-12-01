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

static int	get_len(unsigned int n, unsigned int base_len)
{
	unsigned int	len;

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

char	*itoa_u_and_prec(unsigned int n, unsigned int prec, unsigned int base_len)
{
	char			*r;
	char			*base;
	unsigned int	len;

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
