/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 19:20:16 by arguilla          #+#    #+#             */
/*   Updated: 2020/12/01 19:20:19 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATOR_H
# define VALIDATOR_H

t_bool		is_flag(char c);
t_bool		is_specifier(char c);
t_bool		is_negative(int *nb);
void		check_number_or_asterisk(char *str, size_t *j);

#endif
