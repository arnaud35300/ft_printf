/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 19:30:04 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/14 19:37:58 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	assign_flag(t_arg *arg_control, char flag)
{
	if (flag == '-')
		arg_control->flag_negative = TRUE;
	if (flag == '0')
		arg_control->flag_zero = TRUE;
	if (flag == '*')
		arg_control->flag_star = TRUE;
}
