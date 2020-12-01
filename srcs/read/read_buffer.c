/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_buffer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 20:30:33 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/26 20:28:35 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Read the buffer property into buffer structure.
**
** @param	buffer	=> the buffer structure.
**
** @return	void.
*/

void		read_buffer(t_buffer *buffer)
{
	write(buffer->fd, buffer->buffer, buffer->index);
}
