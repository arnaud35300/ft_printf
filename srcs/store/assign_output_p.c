/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_output_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 14:58:00 by arguilla          #+#    #+#             */
/*   Updated: 2020/12/01 19:58:55 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*assign_output_p(t_format *format, void *nb)
{
	uint	blen;

	blen = 16;
	if (nb == NULL)
		return (ft_strdup("(nil)"));
	if (format->precision == '.')
		return (itoa_lu_and_prec((uintptr_t)nb, format->precision_width, blen));
	if (format->flags == '0')
		return (itoa_lu_and_prec((uintptr_t)nb, format->width, blen));
	return (itoa_lu_and_prec((uintptr_t)nb, 0, blen));
}
