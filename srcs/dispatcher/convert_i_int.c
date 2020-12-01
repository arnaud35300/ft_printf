/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_i_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 09:29:10 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/26 18:28:52 by arguilla         ###   ########.fr       */
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

bool		convert_i_int(t_printf *pf, va_list *ap)
{
	return (convert_d_int(pf, ap));
}
