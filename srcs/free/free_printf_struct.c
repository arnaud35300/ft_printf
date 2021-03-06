/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_printf_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 09:00:01 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/26 11:41:27 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** free printf structure.
**
** @param	pf	=> the printf structure to free.
** @param	r	=> the code response to return.
**
** @return	r.
*/

t_bool		free_printf_struct(t_printf *pf, t_bool response)
{
	free(pf);
	return (response);
}
