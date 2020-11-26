/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_d_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 09:28:49 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/26 08:00:14 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char *assign_output(t_format *format, int nb)
{
	if (nb == 0 && format->precision == '.' && format->precision_width == 0)
		return (ft_strdup(""));
	if (format->precision == '.')
		return (itoa_and_prec(nb, format->precision_width));
	if (format->flags == '0')
		return (itoa_and_prec(nb, format->width));
	return (itoa_and_prec(nb, 0));
}

bool		convert_d_int(t_printf *pf, va_list *ap)
{
	char	*output;
	int		nb;

	clean_flag_and_precision(&(pf->format));
	nb = va_arg(*ap, int);
	output = assign_output(&(pf->format), nb);
	if (!output)
		return (EXIT_ERROR);
	if (pf->format.flags == '-')
		store_output(pf, output, SPACE_AFTER);
	else
		store_output(pf, output, SPACE_BEFORE);
	free(output);
	return (1);
}
