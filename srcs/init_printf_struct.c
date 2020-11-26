/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_printf_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 19:47:06 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/21 08:27:27 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_printf	*init_printf_struct(const char *content)
{
	t_printf	*pf;

	pf = malloc(sizeof(t_printf));
	if (!pf)
		return (pf);
	pf->len = 0;
	pf->str = ft_strdup(content);
	if (!pf->str)
	{
		pf = NULL;
		return (pf);
	}
	pf->format.flags = NO_FLAG;
	pf->format.width = NO_WIDTH;
	pf->format.precision = NO_PRECISION;
	pf->format.precision_width = NO_PREC_WIDTH;
	pf->format.type = NO_TYPE;
	pf->buffer.index = 0;
	pf->buffer.fd = 1;
	return (pf);
}
