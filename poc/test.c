#include "libft.h"
#include <stdio.h>
#include <locale.h>

main()
{
	setlocale(LC_ALL, "");
	ft_printf("mine %15.4ls\n", L"我是一只猫。");
	printf("offi %15.4ls\n", L"我是一只猫。");
	/* ft_printf("%ls", L"我是一只猫。"); */
}
