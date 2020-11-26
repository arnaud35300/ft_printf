/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_output_u.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 08:12:01 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/26 08:36:09 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *assign_output_u(t_format *format, unsigned int nb)
{
	if (nb == 0 && format->precision == '.' && format->precision_width == 0)
		return (ft_strdup(""));
	if (format->precision == '.')
		return (itoa_u_and_prec(nb, format->precision_width));
	if (format->flags == '0')
		return (itoa_u_and_prec(nb, format->width));
	return (itoa_u_and_prec(nb, 0));
}
