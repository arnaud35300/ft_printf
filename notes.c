/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   notes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 08:30:37 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/14 08:42:24 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* FLAGS */

/* FLAGS '-'
 * 
 * permet de specifier vers quel sens doivent etre ajouter les espaces blanc 
 *
 */

/* FLAGS '0'
 *
 * ajoute des 0 vers la gauche, il est ignore s'il y a deja un flag '-'
 *
 */

/* WIDTH */

/* %[FLAGS]10d\n ---> cela va ajouter x espace blanc devant pour arriver a cette taille
 *
 * Si %d = 10, il faudra 8 espaces blanc pour arriver a 10
 * si %d = 1000, il faudra 6 espaces blanc pour arriver a 10 
 * etc...
 *
 * !ATTENTION
 *
 * Precede du FLAGS '-', les x espaces seront ajoutes a la fin
 *
 * (sans flag '-') "        10" ---> devient ---> "10        " (avec flag '-')
 *
 */
