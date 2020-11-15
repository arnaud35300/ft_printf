/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 09:14:02 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/15 20:22:35 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *fmt, ...)
{
	t_printf	*pf;
	va_list		ap;

	if (!fmt)
		return (EXIT_ERROR);

	pf = init_printf_struct(fmt);
	if (!pf)
		return (EXIT_ERROR);
	va_start(ap, fmt);
	printf("%s\n", pf->str);
	/*
	while (*fmt)
	{
		if (*fmt == '%' && *(fmt + 1))
			break;
		else
			break;
		fmt++;
	}
	*/
	va_end(ap);
	return (0);
}

int main(void)
{
	ft_printf("Yoooi %   % %");
}
