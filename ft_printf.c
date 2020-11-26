/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 09:14:02 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/26 07:57:31 by arguilla         ###   ########.fr       */
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
	ft_printf("%d\n", ft_printf("Coucou  %10.20d %34.*d%-*.*d %d\n", 4, 12, 10, 10, 2, 0,32));
	printf("%d\n", printf("Coucou  %10.20d %34.*d%-*.*d %d\n", 4, 12, 10, 10, 2, 0,32));
}
