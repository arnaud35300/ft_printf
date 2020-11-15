/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 09:14:02 by arguilla          #+#    #+#             */
/*   Updated: 2020/11/14 19:40:43 by arguilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#define DEBUG 0
int	ft_printf(const char *fmt, ...)
{
	int i = 0;
	int *pointer = &i;
#if DEBUG == 1
	printf("string sans arguments \n");
	
	printf("nombres %%d : %d\n", 10);
	printf("nombres neg %%d : %d\n", -10);

	printf("string %%s : %s\n", "string");

	printf("char %%c : %c\n", 'c');

	printf("pointeur %%p : %p\n", pointer);

	printf("nombres avec base %%i : %i\n", 10);
	
	printf("unsigned int %%u : %u\n", 10);
	printf("unsigned int neg %%u : %u\n", -10);

	printf("hexadecimal %%x : %x\n", 29);
	printf("hexadecimal %%X : %X\n", 29);
#endif
	/*
	** FLAGS %[flags][width][.precision][length]specifier
	*/

	printf("\n-F-L-A-G-S--F-L-A-G-S--F-L-A-G-S-\n\n");
	

	printf("nombres %%d : %20.12d\n", 10);

	//printf("nombres neg %%d : %-5d\n", -10);

	printf("string %%s : %s\n", "string");

	/*
	printf("char %%c : %c\n", 'c');

	printf("pointeur %%p : %p\n", pointer);

	printf("nombres avec base %%i : %i\n", 10);
	
	printf("unsigned int %%u : %u\n", 10);
	printf("unsigned int neg %%u : %u\n", -10);

	printf("hexadecimal %%x : %x\n", 29);
	printf("hexadecimal %%X : %X\n", 29);

*/
	(void)pointer;
	(void)fmt;
	return (0);
}

int main(void)
{
	ft_printf("Yooo");
}
