/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_clean_buffer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 08:24:01 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/18 08:24:54 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Read and clean the buffer property into buffer structure.
**
** @param	buffer	=> the buffer structure.
**
** @return	void.
*/

void		read_and_clean_buffer(t_buffer *buffer)
{
	read_buffer(buffer);
	clean_buffer(buffer);
}
