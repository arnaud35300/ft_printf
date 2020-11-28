/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_d_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 09:28:49 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/28 13:27:14 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool		convert_d_int(t_printf *pf, va_list *ap)
{
	char	*output;
	int		nb;

	clean_flag_and_precision(&(pf->format));
	nb = va_arg(*ap, int);
	if (pf->format.type == u || pf->format.type == x || pf->format.type == X)
		output = assign_output_u(&(pf->format), nb);
	else
		output = assign_output(&(pf->format), nb);
	if (!output)
		return (EXIT_ERROR);
	if (pf->format.flags == '-')
		store_output(pf, output, ft_strlen(output), SPACE_AFTER);
	else
		store_output(pf, output, ft_strlen(output), SPACE_BEFORE);
	free(output);
	return (TRUE);
}
