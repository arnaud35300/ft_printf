/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_u_and_prec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 08:31:32 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/26 08:51:55 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

static int	get_absolute(int n)
{
	if (n > 0)
		return (n);
	return (-n);
}

static int	get_len(unsigned int n)
{
	unsigned int	len;

	len = 0;
	if (n <= 0)
		++len;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static void assign_value(unsigned int *len, int *len_and_prec, int *n, unsigned int *prec)
{
	*len = get_len(*n);
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

char	*itoa_u_and_prec(unsigned int n, unsigned int prec)
{
	char	*r;
	unsigned int		len;
	int		len_and_prec;

	assign_value(&len, &len_and_prec, &n, &prec);
	r = malloc(sizeof(char) * (len_and_prec + 1));
	if (!r)
		return (NULL);
	assign_width(r, &prec);
	r[len_and_prec] = '\0';	
	if (n == 0)
		r[0] = '0';
	else if (n < 0)
		r[0] = '-';
	else
		r[0] = '0';
	while (n != 0)
	{
		--len_and_prec;
		r[len_and_prec] = get_absolute(n % 10) + '0';
		n = n / 10;
	}
	return (r);
}
