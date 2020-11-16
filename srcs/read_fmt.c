/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_fmt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 15:54:11 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/16 21:49:02 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
bool		read_fmt(t_printf *pf, va_list *ap)
{
	size_t	i;

	i = 0;
	clean_buffer(&(pf->buffer));

	/*
	printf("\n index %ld\n and buffer : %s\n", pf->buffer.index, pf->buffer.buffer);
	pf->buffer.buffer[5] = '\0';
	if (pf->buffer.buffer[5] == '\0')
		write(1, "true\n", 5);
	if (pf->buffer.buffer[4] == 'a')
		write(1, "true\n", 5);
	if (pf->buffer.buffer[3] == 'a')
		write(1, "true\n", 5);
	if (pf->buffer.buffer[2] == '\0')
		write(1, "true\n", 5);
	if (pf->buffer.buffer[1] == '\0')
		write(1, "true\n", 5);
	*/
	while (pf->str[i])
	{
		//printf("-- buffer.index : %ld \t BUFFER_SIZE: %d\n", pf->buffer.index, BUFFER_SIZE);
		if (pf->buffer.index >= BUFFER_SIZE)
		{
			write(1, "\n", 1); 
			//ft_putstr_fd("fin buffer\n", 1);
			read_buffer(&(pf->buffer));
			clean_buffer(&(pf->buffer));
		}
		pf->buffer.buffer[pf->buffer.index] = pf->str[i];
		i++;
		pf->buffer.index++;
		pf->len++;
	}

	write(1, "\n", 1); 
	read_buffer(&(pf->buffer));

	write(1, "\n", 1); 
	clean_buffer(&(pf->buffer));
	//printf("%ld\n", pf->buffer.index);
	(void)ap;
	return (1);
}
