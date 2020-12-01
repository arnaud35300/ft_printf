/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 19:18:32 by arguilla          #+#    #+#             */
/*   Updated: 2020/12/01 19:18:39 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_H
# define CONVERTER_H

char		*itoa_and_prec(long n, t_uint prec, long base_len, t_bool is_prec);
char		*itoa_u_and_prec(t_uint n, t_uint prec, t_uint base_len);
char		*itoa_lu_and_prec(t_ulong n, t_ulong prec, t_ulong base_len);

#endif
