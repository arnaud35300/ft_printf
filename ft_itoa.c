/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 15:18:58 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/29 15:00:10 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <unistd.h>
/*
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
*/
size_t	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
/*
void	*ft_memset(void *s, int c, size_t n)
{
	char *r;

	r = s;
	while (n)
	{
		*(char *)s = c;
		s++;
		n--;
	}
	return (r);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t src_len;

	src_len = ft_strlen(src);
	if (!size)
		return (src_len);
	while (*src && (size - 1))
	{
		*dst = *src;
		size--;
		dst++;
		src++;
	}
	*dst = '\0';
	return (src_len);
}

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

char	*itoa_u_and_prec(long unsigned int n, long unsigned int prec, long unsigned int base_len)
{
	char			*r;
	char			*base;
	long unsigned int	len;

	len = get_len(n, base_len);
	if (prec > len)
		len = prec;
	r = malloc(sizeof(char) * (len + 1));
	base = malloc(sizeof(char) * (base_len + 1));
	if (!base || !r)
		return (NULL);
	ft_memset(r, '0', len);
	ft_strlcpy(base, "0123456789abcdef", base_len + 1);
	r[len] = '\0';
	while (n != 0)
	{
		--len;
		r[len] = base[n % base_len];
		n = n / base_len;
	}
	free(base);
	return (r);
}

*/

int		ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}
int		ft_putchar(int c)
{
	write(1, &c, 1);
}

char	display_p_hex(int n)
{
	if (n >= 0 && n < 10)
		return ('0' + n);
	else
		return ('a' + n - 10);
}
#include <stdint.h>
int		display_p(void *ptr)
{
	int			count;
	int			i;
	uintptr_t	p;

	count = 0;
	p = (uintptr_t)ptr;
	p = ULONG_MAX;
	count += ft_putstr("0x");
	if (!p)
		return ((count += ft_putchar('0')));
	i = (sizeof(p << 3 ) * 2 );
	//printf("%d\n", i);
	while (i > 0)
	{
		if ((p >> i) & 0xf)
			count += ft_putchar((p >> i) & 0xf);
		i -= 4;
	}
	return (count);
}

int main(int ac, char **av)
{
	int a = 1;
	int *ptr = &a;

	display_p(ptr);

	printf("\n%p\n", (void *)ULONG_MAX);

	printf("%020p", NULL);
	//printf("\n%p\n", ptr);

	//printf("Ox%s\n",itoa_u_and_prec((uintptr_t)ptr, 0, 16));
	//printf("%p\n", ptr);
}

