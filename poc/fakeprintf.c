#include <stdarg.h>
#include <stdio.h>
/* #include < */

void	print(char *str, ...)
{
	va_list ap;
	char	*arg;

	va_start(ap, str);
	while (*str)
	{
		if	(*str == '%' && *(str + 1) == 's')
		{
			arg = va_arg(ap, char*);
			printf("%s", arg);
			str++;
		}
		else
			printf("%c", *str);
		str++;
	}
}

int		main()
{
	print("hello %s fucking %%s, fuck the 1%", "cruel",  "world");
}
