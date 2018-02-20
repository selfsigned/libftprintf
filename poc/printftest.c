#include "libft.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	int		res;
	int		res2;

	if (ac != 3)
		return (1);
	res = ft_printf(av[1], av[2], 42);
	ft_putchar('\n');
	res2 = printf(av[1], av[2], 42);
	printf("\nft_printf output: %d printf output: %d", res, res2);
}
