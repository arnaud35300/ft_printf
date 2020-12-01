/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 19:19:10 by arguilla          #+#    #+#             */
/*   Updated: 2020/12/01 19:19:13 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPATCHER_H
# define DISPATCHER_H

t_bool		dispatch_argument(t_printf *pf, va_list *ap);
t_bool		convert_char(t_printf *pf, va_list *ap);
t_bool		convert_str(t_printf *pf, va_list *ap);
t_bool		convert_ptr(t_printf *pf, va_list *ap);
t_bool		convert_d_int(t_printf *pf, va_list *ap);
t_bool		convert_i_int(t_printf *pf, va_list *ap);
t_bool		convert_u_int(t_printf *pf, va_list *ap);
t_bool		convert_hex_l(t_printf *pf, va_list *ap);
t_bool		convert_hex_u(t_printf *pf, va_list *ap);
t_bool		convert_percent(t_printf *pf, va_list *ap);

#endif
