/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 12:12:50 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/14 12:36:54 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 ** The function choose if the arguments are corrects and if isn't true,
 ** the function print the current character ('%').
*/

void	display_arg(const char *arg)
{
	if (!check_arg(arg))
		ft_putchar_fd(*arg, STDOUT);
}
