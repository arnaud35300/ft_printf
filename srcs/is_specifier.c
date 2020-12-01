/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_specifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 08:53:25 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/30 18:22:43 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool		is_specifier(char c)
{
	return (c == FMT_CHAR || c == FMT_STR || c == FMT_PTR || c == FMT_D_INT
			|| c == FMT_I_INT || c == FMT_U_INT || c == FMT_HEX_L
			|| c == FMT_HEX_U || c == FMT_META_CHAR);
}
