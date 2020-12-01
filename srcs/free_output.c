/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 20:12:58 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/30 20:16:47 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	free_output(char *output, bool response)
{
	free(output);
	return (response);
}
