/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_u_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 09:31:19 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/26 11:11:46 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool		convert_u_int(t_printf *pf, va_list *ap)
{
/*	char			*output;
	int	nb;

	clean_flag_and_precision(&(pf->format));
	nb = va_arg(*ap, int);
	output = assign_output_u(&(pf->format), nb);
	if (!output)
		return (EXIT_ERROR);
	if (pf->format.flags == '-')
		store_output(pf, output, SPACE_AFTER);
	else
		store_output(pf, output, SPACE_BEFORE);
	free(output);
	*/
	return (convert_d_int(pf, ap));
}
