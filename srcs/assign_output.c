/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 08:12:01 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/29 20:49:52 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *assign_output(t_format *format, int nb)
{
	int base_len;

	base_len = 10;
	if (nb == 0 && format->precision == '.' && format->precision_width == 0)
		return (ft_strdup(""));
	if (format->precision == '.')
		return (itoa_and_prec(nb, format->precision_width, base_len, TRUE));
	if (format->flags == '0')
		return (itoa_and_prec(nb, format->width, base_len, FALSE));
	return (itoa_and_prec(nb, 0, base_len, FALSE));
}
