/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_printf_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 09:00:01 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/26 11:41:27 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool		free_printf_struct(t_printf *pf, bool response)
{
	free(pf);
	return (response);
}
