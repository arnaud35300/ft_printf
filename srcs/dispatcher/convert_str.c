/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 09:25:36 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/30 20:44:21 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*store_unvalid_str(t_printf *pf)
{
	if (pf->format.precision == '.' && pf->format.precision_width < 6)
		return (ft_strdup(""));
	else
		return (ft_strdup("(null)"));
}

static char		*store_valid_str(t_printf *pf, char *arg)
{
	char	*output;
	size_t	len;

	len = ft_strlen(arg);
	if (pf->format.precision_width < len && pf->format.precision == '.')
		len = pf->format.precision_width;
	output = malloc(sizeof(char) * (len + 1));
	if (!output)
		return (NULL);
	ft_strlcpy(output, arg, len + 1);
	return (output);
}

bool		convert_str(t_printf *pf, va_list *ap)
{
	char	*arg;
	char	*output;

	arg  = va_arg(*ap, char *);
	if (arg == NULL)
		output = store_unvalid_str(pf);
	else
		output = store_valid_str(pf, arg);
	if (!output)
		return (free_output(output, EXIT_ERROR));
	if (pf->format.flags == '-')
		store_output(pf, output, ft_strlen(output), SPACE_AFTER);
	else
		store_output(pf, output, ft_strlen(output), SPACE_BEFORE);
	return (free_output(output, TRUE));
}