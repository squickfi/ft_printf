#include "libftprintf.h"

t_info	init_flags(void)
{
	t_info	flags;

	flags.sign = 0;
	flags.zero = ' ';
	flags.star = 0;
	flags.width = 0;
	flags.precision = -1;
	flags.specifier = 0;
	flags.d_s = 0;
	return (flags);
}

int	ft_print(va_list argptr, char *s)
{
	t_info	flags;
	int		length;

	length = 0;
	while (*s)
	{
		if (*s != '%')
		{
			write(1, s, 1);
			s++;
			length++;
		}
		else if (*s++ == '%')
		{
			flags = init_flags();
			s += ft_parse_flags(s, &flags, argptr);
			if (flags.specifier)
				length += ft_print_values(flags, argptr);
		}
	}
	return (length);
}

int	ft_printf(const char *s, ...)
{
	va_list	argptr;
	int		length;

	va_start(argptr, s);
	length = ft_print(argptr, (char *)s);
	va_end(argptr);
	return (length);
}
