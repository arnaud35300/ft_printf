/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_argument.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 07:56:57 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/21 11:48:01 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	dispatch_argument(t_printf *pf, va_list *ap, size_t *i)
{
	t_func *tab[8];

	assign_tab_converter(tab);
	return ((*tab[pf->format.type])(pf, ap));
}
