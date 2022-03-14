#include "libftprintf.h"

int	ft_print_d_help_2(int d, t_info flags, int fulllen, int len)
{
	int	count;

	count = 0;
	if (flags.precision >= 0)
	{
		count += ft_putchars_fd(' ', flags.width - fulllen - flags.d_s, 1);
		count += ft_putchars_fd('-', flags.d_s, 1);
		count += ft_putchars_fd('0', fulllen - len, 1);
		count += ft_putnbr_base_fd(d, 10, 0, 1);
	}
	else
	{
		if (flags.zero == ' ')
			count += ft_putchars_fd(flags.zero, flags.width - \
			len - flags.d_s, 1);
		count += ft_putchars_fd('-', flags.d_s, 1);
		if (flags.zero == '0')
			count += ft_putchars_fd(flags.zero, flags.width - \
			len - flags.d_s, 1);
		count += ft_putnbr_base_fd(d, 10, 0, 1);
	}
	return (count);
}

int	ft_print_d_help(int d, t_info flags, int fulllen, int len)
{
	int	count;

	count = 0;
	if (!flags.sign)
		count += ft_print_d_help_2(d, flags, fulllen, len);
	else
	{
		count += ft_putchars_fd('-', flags.d_s, 1);
		count += ft_putchars_fd('0', fulllen - len, 1);
		count += ft_putnbr_base_fd(d, 10, 0, 1);
		count += ft_putchars_fd(' ', flags.width - fulllen - flags.d_s, 1);
	}
	return (count);
}

int	ft_print_d(t_info flags, va_list argptr)
{
	int	d;
	int	count;
	int	len;
	int	fulllen;

	count = 0;
	flags.d_s = 0;
	d = va_arg(argptr, int);
	if (flags.precision == 0 && d == 0)
	{
		count += ft_putchars_fd(' ', flags.width, 1);
		return (count);
	}
	len = howmanychars(d, 10);
	if (d < 0)
		flags.d_s = 1;
	if (flags.precision > len)
		fulllen = flags.precision;
	else
		fulllen = len;
	count += ft_print_d_help(d, flags, fulllen, len);
	return (count);
}
