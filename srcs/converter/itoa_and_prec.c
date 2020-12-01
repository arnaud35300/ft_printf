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

static long int		get_absolute(long int n)
{
	if (n > 0)
		return (n);
	return (-n);
}

static unsigned int			get_len(long int n, long int base_len)
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

static unsigned int	get_prec(long int n, unsigned int prec, bool is_prec)
{
	if (n < 0 && is_prec)
		return (++prec);
	return (prec);
}

char				*itoa_and_prec(long int n, unsigned int prec, long int base_len, bool is_prec)
{
	char			*r;
	char			*base;
	unsigned int	len;

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
