#include <stdio.h>
#include "includes/ft_printf.h"

int main(void)
{
	//ft_printf("%.3s", NULL);
	//printf("printf : %d\n", printf("%2.9p\n", 1234));
	//printf("ft_printf : %d\n", ft_printf("%c%c%c%c%c", 1,2,3,4,5));	
	ft_printf("%.*d", 3, -12);
	printf("%.*d", 3, -12);
	fflush(stdout);
	ft_printf("%0*d", 3, -12);
	printf("%*d", 3, -12);
	fflush(stdout);
}
