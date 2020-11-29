/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 09:14:02 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/29 17:27:50 by arguilla         ###   ########.fr       */
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
/*
int main(void)
{
	
	ft_printf("%d\n", ft_printf("Coucou  %10.20d %34.*d%-*.*d %d %d %d %d\n", 4, 12, 10, 10, 2, 0,32,-0, -5, -120000));
	   printf("%d\n",    printf("Coucou  %10.20d %34.*d%-*.*d %d %d %d %d\n", 4, 12, 10, 10, 2, 0,32,-0, -5, -120000));
	fflush(stdout);
	ft_printf("%u %*.u %*.u %2.10u\n",UINT_MAX, -12, -13, -1, 78, -9888);
	   printf("%u %*.u %*.u %2.10u\n",UINT_MAX, -12, -13, 2, 78, -9888);
	fflush(stdout);
	ft_printf("%-*.*u\n", 5, -4, 10);
	   printf("%-*.*u\n", 5, -4, 10);
	fflush(stdout);
	ft_printf("test : %u %010u\n", 5, 10);
	   printf("test : %u %010u\n", 5, 10);
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
	ft_printf("hex:%X %20.10X %-25.2X\n", 10, -30, -12);
	   printf("hex:%X %20.10X %-25.2X\n", 10, -30, -12);
	fflush(stdout);
	ft_printf("%s %10s %-10.2s %12.23s %.s\n", "coucou", "heyheyhey", "bonjour", "lalalalila", "tictac");
	  printf("%s %10s %-10.2s %12.23s %.s\n", "coucou", "heyheyhey", "bonjour", "lalalalila", "tictac");
	fflush(stdout);
	ft_printf("%%\n");
	   printf("%%\n");
	fflush(stdout);

	ft_printf("%10p %p %p %p\n", NULL, (void *)100, (void *)UINT_MAX, (void *)0);
	   printf("%10p %p %p %p\n", NULL, (void *)100, (void *)UINT_MAX, (void *)0);
	fflush(stdout);
	ft_printf("%p\n", NULL);
	   printf("%p\n", (void *)1);
	fflush(stdout);
}*/
