/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 19:50:28 by arguilla          #+#    #+#             */
/*   Updated: 2020/12/01 19:51:44 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** free base string.
**
** @param	base	=> the string to free.
** @param	r		=> the string to return.
**
** @return	r.
*/

char	*free_itoa(char *base, char *r)
{
	free(base);
	return (r);
}
