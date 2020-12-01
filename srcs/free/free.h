/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 19:19:18 by arguilla          #+#    #+#             */
/*   Updated: 2020/12/01 19:52:18 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H

bool		free_printf_struct(t_printf *pf, bool response);
bool		free_output(char *output, bool response);
char		*free_itoa(char *base, char *r);

#endif
