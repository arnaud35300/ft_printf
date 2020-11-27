/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 09:14:02 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/27 19:44:34 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *fmt, ...)
{
	t_printf	*pf;
	va_list		ap;
	int			result;
	if (!fmt)
		return (EXIT_ERROR);
	pf = init_printf_struct(fmt);
	if (!pf)
		return (EXIT_ERROR);
	va_start(ap, fmt);
	read_fmt(pf, &ap);
	va_end(ap);
	result = pf->len;
	//printf("%d\n", pf->format.width);
	free_printf_struct(pf);
	return (result);
}

int main(void)
{
	ft_printf("%d\n", ft_printf("Coucou  %010d\n", 4));
	ft_printf("%d\n", ft_printf("Coucou  %10.20d %34.*d%-*.*d %d %d %d %d\n", 4, 12, 10, 10, 2, 0,32,-0, -5, -120000));
	   printf("%d\n",    printf("Coucou  %10.20d %34.*d%-*.*d %d %d %d %d\n", 4, 12, 10, 10, 2, 0,32,-0, -5, -120000));
	fflush(stdout);
	ft_printf("%*.u %*.u %2.10u\n", -12, -13, -1, 78, -9888);
	   printf("%*.u %*.u %2.10u\n", -12, -13, 2, 78, -9888);
	fflush(stdout);
	ft_printf("%-*.*u\n", 5, -4, 10);
	   printf("%-*.*u\n", 5, -4, 10);
	fflush(stdout);
	ft_printf("test: %u %010u\n", 5, 10);
	   printf("test: %u %010u\n", 5, 10);
	fflush(stdout);
	ft_printf("test max: %u\n", 300000000);
	   printf("test max: %u\n", 300000000);
	fflush(stdout);
	ft_printf("i: %i %10.2i%.i\n", 0x32, 012, -12);
	   printf("i: %i %10.2i%.i\n", 0x32, 012, -12);
	fflush(stdout);
	ft_printf("c: %c %10c%-12c\n", 'e', 'A', 380);
	   printf("c: %c %10c%-12c\n", 'e', 'A', 380);
	fflush(stdout);
	ft_printf("null:%c\n", '\0');
	   printf("null:%c\n", '\0');
	fflush(stdout);
	ft_printf("hex:%x %20.10x %-25.2x\n", 10, -30, -12);
	   printf("hex:%x %20.10x %-25.2x\n", 10, -30, -12);
	fflush(stdout);
}
