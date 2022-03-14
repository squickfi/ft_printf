#include "libftprintf.h"

int	ft_print_values(t_info flags, va_list argptr)
{
	int	length;

	length = 0;
	if (flags.specifier == 'c')
		length = ft_print_c(flags, argptr);
	if (flags.specifier == 's')
		length = ft_print_s(flags, argptr);
	if (flags.specifier == 'p')
		length = ft_print_p(flags, argptr);
	if (flags.specifier == 'd' || flags.specifier == 'i')
		length = ft_print_d(flags, argptr);
	if (flags.specifier == 'u')
		length = ft_print_u(flags, argptr);
	if (flags.specifier == 'x')
		length = ft_print_x(flags, argptr);
	if (flags.specifier == 'X')
		length = ft_print_xx(flags, argptr);
	if (flags.specifier == '%')
		length = ft_print_persent(flags);
	return (length);
}
