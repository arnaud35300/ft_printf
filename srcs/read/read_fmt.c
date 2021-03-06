/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_fmt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 15:54:11 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/30 20:46:41 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Read string and delegate to other functions according to the content of
** this one.
**
** @param	pf	=> the printf structure which contains the string to
** traveling.
** @param	ap	=> the ap structure which contains the list of arguments.
**
** @return	boolean value, EXIT_ERROR if malloc fails.
*/

t_bool		read_fmt(t_printf *pf, va_list *ap)
{
	size_t	i;

	i = 0;
	clean_buffer(&(pf->buffer));
	while (pf->str[i])
	{
		if (pf->buffer.index >= BUFFER_SIZE)
			read_and_clean_buffer(&(pf->buffer));
		if (pf->str[i] == FMT_META_CHAR)
		{
			if (read_argument(pf, ap, &i) == EXIT_ERROR)
				return (EXIT_ERROR);
		}
		else
			store_char(pf, &i);
	}
	read_and_clean_buffer(&(pf->buffer));
	return (TRUE);
}
