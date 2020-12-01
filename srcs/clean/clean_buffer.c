/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_buffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 20:25:18 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/26 17:31:45 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Clean the buffer values.
**
** @param	buffer	=> the buffer structure.
**
** @return	void.
*/

void	clean_buffer(t_buffer *buffer)
{
	int i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		buffer->buffer[i] = '\0';
		i++;
	}
	buffer->buffer[i] = '\0';
	buffer->index = 0;
}
