/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_argument_len.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 16:11:54 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/25 08:30:28 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		get_argument_len(t_format *format, char *output)
{
	size_t len;

	len = 0;
	len = ft_strlen(output);
	if (format->precision_width > len)
		len = format->precision_width;
	if (format->width > len)
		len = format->width;
	return (len);
}
