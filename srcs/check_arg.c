/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 11:55:21 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/14 20:17:45 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_arg(const char *arg)
{
	t_arg *arg_control;
	int i;
	
	arg_control = init_struct();
	if (!arg_control)
		return (FALSE);
	i = 0;
	while (is_flag(arg[i]))
	{
		assign_flag(arg_control, arg[i]);
		i++;
	}
	(void)arg;
	return (1);
}
