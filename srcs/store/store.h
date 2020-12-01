/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 19:19:49 by arguilla          #+#    #+#             */
/*   Updated: 2020/12/01 20:06:05 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STORE_H
# define STORE_H

t_printf	*init_printf_struct(const char *content);
void		store_char(t_printf *pf, size_t *i);
bool		store_argument(t_printf *pf, va_list *ap, size_t *i);
int			store_number_or_asterisk(char *str, size_t *j,
			va_list *ap, t_format *format);
char		move_str_index(char c, char *compare, size_t *j);
void		store_output(t_printf *pf, char *output,
			size_t output_len, bool order);
char		*assign_output(t_format *format, int nb);
char		*assign_output_u(t_format *format, uint nb);
char		*assign_output_p(t_format *format, void *nb);
void		assign_tab_converter(t_func **tab);

#endif
