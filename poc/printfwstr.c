#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <unistd.h>
#include <wchar.h>

int		main(int ac, char **av)
{
	int		res;
	int		res2;

	(void)ac;
	setlocale(LC_ALL, "");
	res = ft_printf(av[1], L"🤔really makes think doesn't it?😎");
	ft_putchar('\n');
	res2 = printf(av[1], L"🤔really makes think doesn't it?😎");
	printf("\nft_printf output: %d printf output: %d", res, res2);
	/* res = ft_printf(av[1], 0); */
	/* ft_putchar('\n'); */
	/* res2 = printf(av[1], 0); */
	/* printf("\nft_printf output: %d printf output: %d", res, res2); */
}
