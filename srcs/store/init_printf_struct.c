/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_printf_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 19:47:06 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/26 17:31:02 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Initialize properties of the printf structure.
**
** @param	content	=> the content string is the first parameters
** of the ft_printf functions.
**
** @return	the printf structure.
*/

t_printf	*init_printf_struct(const char *content)
{
	t_printf	*pf;

	pf = malloc(sizeof(t_printf));
	if (!pf)
		return (pf);
	pf->len = 0;
	pf->str = (char *)content;
	pf->format.flags = NO_FLAG;
	pf->format.width = NO_WIDTH;
	pf->format.precision = NO_PRECISION;
	pf->format.precision_width = NO_PREC_WIDTH;
	pf->format.type = NO_TYPE;
	pf->buffer.index = 0;
	pf->buffer.fd = 1;
	return (pf);
}
