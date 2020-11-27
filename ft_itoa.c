/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:18:58 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/27 17:47:13 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <unistd.h>

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

static void assign_value(unsigned int *len, int *len_and_prec, int *n, unsigned int *prec)
{
	*len_and_prec = *len;
	if (*len < *prec)
		*len_and_prec = *prec;
	*prec -= *len;
}

static void	assign_width(char *r, int *prec)
{
	int j;

	j = 0;
	while (j <= *prec)
	{
		++j;
		r[j] = '0';	
	}
}
#include "libft/libft.h"

char	*itoa_u_and_prec(unsigned int n, unsigned int prec, unsigned int base_len)
{
	char	*r;
	unsigned int		len;
	int		len_and_prec;
	char	*base;

	len = get_len(n, base_len);
	assign_value(&len, &len_and_prec, &n, &prec);
	r = malloc(sizeof(char) * (len_and_prec + 1));
	base = malloc(sizeof(base_len) + 2);
	if (!r || !base)
		return (NULL);
	ft_strlcpy(base, "0123456789abcdef", base_len);
	assign_width(r, &prec);
	r[len_and_prec] = '\0';	
	r[0] = '0';
	while (n != 0)
	{
		--len_and_prec;
		r[len_and_prec] = base[n % base_len];
		n = n / base_len;
	}
	return (r);
}

int main(int ac, char **av)
{
	(void)ac;
	(void)av;	

	int a = -30;
	printf("%s\n", itoa_u_and_prec(INT_MAX, 10, 10));
	//printf("%s\n", itoa_u_and_prec(-30, 0, 15));
}
