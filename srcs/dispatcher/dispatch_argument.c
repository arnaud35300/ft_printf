/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch_argument.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 07:56:57 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/30 18:16:23 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Dispatch to the right function according to the value of the type of the
** current argument.
**
** @param	pf	=> the printf structure.
** @param	ap	=> the ap structure which contains the list of arguments.
**
 ** @return	boolean value, EXIT_ERROR if malloc fails.
*/

t_bool	dispatch_argument(t_printf *pf, va_list *ap)
{
	t_func *tab[9];

	assign_tab_converter(tab);
	return ((*tab[pf->format.type])(pf, ap));
}
