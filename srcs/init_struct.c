/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 19:47:06 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/14 20:17:30 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_arg	*init_struct(void)
{
	t_arg *new_arg_control;

	new_arg_control = malloc(sizeof(t_arg));
	if (!new_arg_control)
		return (new_arg_control);
	new_arg_control->flag_negative = FALSE;
	new_arg_control->flag_zero = FALSE;
	new_arg_control->flag_star = FALSE;
	new_arg_control->precision = FALSE;
	new_arg_control->width = FALSE;
	new_arg_control->type = '\0';
	return (new_arg_control);
}
