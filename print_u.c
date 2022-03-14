#include "libftprintf.h"

int	uns_howmanychars(unsigned int n, int base)
{
	int	count;

	count = 0;
	while (n / base != 0)
	{
		count++;
		n /= base;
	}
	count++;
	return (count);
}

int	ft_print_u_help(unsigned int u, t_info flags, int fulllen, int len)
{
	int	count;

	count = 0;
	if (!flags.sign)
	{
		if (flags.precision >= 0)
		{
			count += ft_putchars_fd(' ', flags.width - fulllen, 1);
			count += ft_putchars_fd('0', fulllen - len, 1);
			count += ft_putnbr_long_base_fd(u, 10, 0, 1);
		}
		else
		{
			count += ft_putchars_fd(flags.zero, flags.width - fulllen, 1);
			count += ft_putnbr_long_base_fd(u, 10, 0, 1);
		}
	}
	else
	{
		count += ft_putchars_fd('0', fulllen - len, 1);
		count += ft_putnbr_long_base_fd(u, 10, 0, 1);
		count += ft_putchars_fd(' ', flags.width - fulllen, 1);
	}
	return (count);
}

int	ft_print_u(t_info flags, va_list argptr)
{
	int				count;
	unsigned int	u;
	int				len;
	int				fulllen;

	count = 0;
	u = (unsigned int)va_arg(argptr, unsigned int);
	if (flags.precision == 0 && u == 0)
	{
		count += ft_putchars_fd(' ', flags.width, 1);
		return (count);
	}
	len = uns_howmanychars(u, 10);
	if (flags.precision > len)
		fulllen = flags.precision;
	else
		fulllen = len;
	count += ft_print_u_help(u, flags, fulllen, len);
	return (count);
}

int	ft_print_persent(t_info flags)
{
	int	count;

	count = 0;
	if (!flags.sign)
		count += ft_putchars_fd(flags.zero, flags.width - 1, 1);
	write(1, &"%%", 1);
	count++;
	if (flags.sign)
		count += ft_putchars_fd(' ', flags.width - 1, 1);
	return (count);
}
