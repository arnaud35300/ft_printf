/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_hex_u.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 09:33:29 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/28 13:23:52 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Store the conversion of the current argument in the buffer.
**
** @param	pf	=> the printf structure.
** @param	ap	=> the ap structure which contains the list of arguments.
**
 ** @return	boolean value, EXIT_ERROR if malloc fails.
*/

t_bool		convert_hex_u(t_printf *pf, va_list *ap)
{
	return (convert_d_int(pf, ap));
}
