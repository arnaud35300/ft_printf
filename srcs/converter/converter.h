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

char		*itoa_and_prec(long n, uint prec, long base_len, bool is_prec);
char		*itoa_u_and_prec(uint n, uint prec, uint base_len);
char		*itoa_lu_and_prec(ulong n, ulong prec, ulong base_len);

#endif
