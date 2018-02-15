#include "libft.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	int		res;

	if (ac != 3)
		return (1);
	res = ft_printf(av[1], av[2]);
	printf("\nft_printf output: %d", res);
}
