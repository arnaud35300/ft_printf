/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 09:25:59 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/30 20:21:42 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool		convert_ptr(t_printf *pf, va_list *ap)
{
	char	*output;
	void	*arg;

	arg = va_arg(*ap, void *);
	output = assign_output_p(&(pf->format), arg);
	if (!output)
		return (free_output(output, EXIT_ERROR));
	if (pf->format.flags == '-')
		store_output(pf, output, ft_strlen(output), SPACE_AFTER);
	else
		store_output(pf, output, ft_strlen(output), SPACE_BEFORE);
	return (free_output(output, TRUE));
}
