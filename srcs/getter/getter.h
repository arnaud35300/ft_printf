/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 19:19:27 by arguilla          #+#    #+#             */
/*   Updated: 2020/12/01 19:19:29 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GETTER_H
# define GETTER_H

int			get_type(char c);
char		get_flags(char *str, size_t *j);
size_t		get_argument_len(t_format *format, char *output);

#endif
