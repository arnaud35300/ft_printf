/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_output_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 14:58:00 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/30 21:19:32 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *assign_output_p(t_format *format, void *nb)
{
	unsigned int base_len;
	(void)format; // remove format parameters
	base_len = 16;
	if (nb == NULL)
		return (ft_strdup("(nil)"));
	if (format->precision == '.')
		return (itoa_lu_and_prec((uintptr_t)nb, format->precision_width, base_len));
	if (format->flags == '0')
		return (itoa_lu_and_prec((uintptr_t)nb, format->width, base_len));
	return (itoa_lu_and_prec((uintptr_t)nb, 0, base_len));
}
