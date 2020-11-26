/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:18:58 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/25 15:02:28 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static int	get_absolute(int n)
{
	if (n > 0)
		return (n);
	return (-n);
}

static int	get_len(int n)
{
	int	len;

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

static void assign_value(int *len, int *len_and_prec, int *n, int *prec)
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
char	*ft_itoa(int n, int prec)
{
	char	*r;
	int		len;
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

int main(void)
{
	//printf("%s\n", ft_itoa(5, 10));
	size_t e = 5;
	size_t a = 10;
	printf("%s\n", ft_itoa(0x10, 10));
	printf("%.d", 1);
	//printf("%s\n", ft_itoa(-50, 10));
	//printf("%s\n", ft_itoa(-5, 3));
}
