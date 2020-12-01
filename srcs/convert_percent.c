/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 18:12:13 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/30 21:02:04 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool		convert_percent(t_printf *pf, va_list *ap)
{
	// FIX TEMPORAIRE !!!!
	write(1, "%", 1);
	pf->len++;
	return (TRUE);
	// FIX POUR PFT 2019
	(void)ap;
	if (pf->format.flags == '-')
		store_output(pf, "%", 1, SPACE_AFTER);
	else
		store_output(pf, "%", 1, SPACE_BEFORE);
	return (TRUE);
}
