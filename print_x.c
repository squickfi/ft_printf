#include "libftprintf.h"

int	ft_print_x_help(unsigned int x, t_info flags, int fulllen, int len)
{
	int	count;

	count = 0;
	if (!flags.sign)
	{
		if (flags.precision >= 0)
		{
			count += ft_putchars_fd(' ', flags.width - fulllen, 1);
			count += ft_putchars_fd('0', fulllen - len, 1);
			count += ft_putnbr_long_base_fd(x, 16, 0, 1);
		}
		else
		{
			count += ft_putchars_fd(flags.zero, flags.width - fulllen, 1);
			count += ft_putnbr_long_base_fd(x, 16, 0, 1);
		}
	}
	else
	{
		count += ft_putchars_fd('0', fulllen - len, 1);
		count += ft_putnbr_long_base_fd(x, 16, 0, 1);
		count += ft_putchars_fd(' ', flags.width - fulllen, 1);
	}
	return (count);
}

int	ft_print_x(t_info flags, va_list argptr)
{
	int				count;
	unsigned int	x;
	int				len;
	int				fulllen;

	count = 0;
	x = (unsigned int)va_arg(argptr, unsigned int);
	if (flags.precision == 0 && x == 0)
	{
		count += ft_putchars_fd(' ', flags.width, 1);
		return (count);
	}
	len = uns_howmanychars(x, 16);
	if (flags.precision > len)
		fulllen = flags.precision;
	else
		fulllen = len;
	count += ft_print_x_help(x, flags, fulllen, len);
	return (count);
}

int	ft_print_xx_help(unsigned int xx, t_info flags, int fulllen, int len)
{
	int	count;

	count = 0;
	if (!flags.sign)
	{
		if (flags.precision >= 0)
		{
			count += ft_putchars_fd(' ', flags.width - fulllen, 1);
			count += ft_putchars_fd('0', fulllen - len, 1);
			count += ft_putnbr_long_base_fd(xx, 16, 1, 1);
		}
		else
		{
			count += ft_putchars_fd(flags.zero, flags.width - fulllen, 1);
			count += ft_putnbr_long_base_fd(xx, 16, 1, 1);
		}
	}
	else
	{
		count += ft_putchars_fd('0', fulllen - len, 1);
		count += ft_putnbr_long_base_fd(xx, 16, 1, 1);
		count += ft_putchars_fd(' ', flags.width - fulllen, 1);
	}
	return (count);
}

int	ft_print_xx(t_info flags, va_list argptr)
{
	int				count;
	unsigned int	xx;
	int				len;
	int				fulllen;

	count = 0;
	xx = (unsigned int)va_arg(argptr, unsigned int);
	if (flags.precision == 0 && xx == 0)
	{
		count += ft_putchars_fd(' ', flags.width, 1);
		return (count);
	}
	len = uns_howmanychars(xx, 16);
	if (flags.precision > len)
		fulllen = flags.precision;
	else
		fulllen = len;
	count += ft_print_xx_help(xx, flags, fulllen, len);
	return (count);
}
