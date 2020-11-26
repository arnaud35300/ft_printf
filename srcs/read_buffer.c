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

void		read_buffer(t_buffer *buffer)
{
	//ft_putstr_fd(buffer->buffer, buffer->fd);
	write(buffer->fd, buffer->buffer, buffer->index);
}
