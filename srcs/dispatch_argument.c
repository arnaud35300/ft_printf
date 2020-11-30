/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_argument.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 07:56:57 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/29 18:00:06 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	dispatch_argument(t_printf *pf, va_list *ap, size_t *i)
{
	t_func *tab[8];
	(void)i; // remove i parameter

	assign_tab_converter(tab);
	return ((*tab[pf->format.type])(pf, ap));
}
