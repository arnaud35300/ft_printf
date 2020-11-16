/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 09:14:02 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/16 21:42:06 by arguilla         ###   ########.fr       */
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
	free_printf_struct(pf);
	return (result);
}

int main(void)
{
	ft_printf("Bonjour je suis une chaine");
}
