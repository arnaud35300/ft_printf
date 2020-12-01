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
# define CONVERTER

char		*itoa_and_prec(long int n, unsigned int prec, long int base_len, bool is_prec);
char		*itoa_u_and_prec(unsigned int n, unsigned int prec, unsigned int base_len);
char		*itoa_lu_and_prec(long unsigned int n, long unsigned int prec, long unsigned int base_len);

#endif
