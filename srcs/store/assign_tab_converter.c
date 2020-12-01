/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_tab_converter.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 09:09:45 by arguilla          #+#    #+#             */
/*   Updated: 2020/12/01 20:04:16 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	assign_tab_converter(t_func **tab)
{
	tab[0] = &convert_char;
	tab[1] = &convert_str;
	tab[2] = &convert_ptr;
	tab[3] = &convert_d_int;
	tab[4] = &convert_i_int;
	tab[5] = &convert_u_int;
	tab[6] = &convert_hex_l;
	tab[7] = &convert_hex_u;
	tab[8] = &convert_percent;
}
