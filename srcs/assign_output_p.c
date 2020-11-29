/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_output_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 14:58:00 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/29 17:21:32 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char *assign_output_p(t_format *format, void *nb)
{
	unsigned int base_len;

	base_len = 16;
	if (nb == NULL)
		return (ft_strdup("(nil)"));
	return (itoa_lu_and_prec((uintptr_t)nb, 0, base_len));
}
