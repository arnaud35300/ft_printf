/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_flag_and_precision.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 12:02:21 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/25 11:37:12 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	clean_flag_and_precision(t_format *format)
{
	if (format->precision == '.' && format->flags == '0')
	{
		format->flags = NO_FLAG;
		format->width = NO_WIDTH;
	}
}
