/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 09:25:36 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/28 16:46:34 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool		convert_str(t_printf *pf, va_list *ap)
{
	char	*arg;
	char	*output;
	size_t	len;

	arg  = va_arg(*ap, char *);
	if (!arg)
		return (EXIT_ERROR);
	len = ft_strlen(arg);
	if (pf->format.precision_width < len && pf->format.precision == '.')
		len = pf->format.precision_width;
	output = malloc(sizeof(char) * (len + 1));
	if (!output)
		return (EXIT_ERROR);
	ft_strlcpy(output, arg, len + 1);
	if (pf->format.flags == '-')
		store_output(pf, output, ft_strlen(output), SPACE_AFTER);
	else
		store_output(pf, output, ft_strlen(output), SPACE_BEFORE);
	free (output);
	return (TRUE);
}
