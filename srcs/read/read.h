/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 19:19:36 by arguilla          #+#    #+#             */
/*   Updated: 2020/12/01 19:19:40 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_H
# define READ_H

bool		read_argument(t_printf *pf, va_list *ap, size_t *i);
bool		read_fmt(t_printf *pf, va_list *ap);
void		read_and_clean_buffer(t_buffer *buffer);
void		read_buffer(t_buffer *buffer);

#endif
