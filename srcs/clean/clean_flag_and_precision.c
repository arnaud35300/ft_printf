/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_flag_and_precision.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 12:02:21 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/29 20:43:45 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	clean_flag_and_precision(t_format *format)
{
	if (format->precision == '.' && format->flags == '0')
		format->flags = NO_FLAG;
}
