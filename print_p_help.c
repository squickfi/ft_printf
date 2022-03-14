#include "libftprintf.h"

int	ft_putnbr_llll_base_fd(unsigned long n, int base, int reg, int fd)
{
	int	count;

	count = 0;
	if (n / base != 0)
	{
		count += ft_putnbr_llll_base_fd(n / base, base, reg, fd);
	}
	if (n % base <= 9)
		ft_putchar_fd(n % base + '0', fd);
	else
	{
		if (reg)
			ft_putchar_fd(n % base + 'A' - 10, fd);
		else
			ft_putchar_fd(n % base + 'a' - 10, fd);
	}
	count++;
	return (count);
}

int	howmanychars_long(unsigned long n, int base)
{
	unsigned long	count;

	count = 0;
	if (n <= 0)
		n = -n;
	while (n / base != 0)
	{
		n /= base;
		count++;
	}
	count++;
	return (count);
}

int	put_p_help(unsigned long p, t_info flags)
{
	int	count;
	int	len;

	count = howmanychars_long(p, 16);
	if (flags.precision > count)
		len = flags.precision;
	else
		len = count;
	if (flags.precision == -1)
		count += ft_putchars_fd(' ', flags.width - count - 2, 1);
	else
		count += ft_putchars_fd(' ', flags.width - len - 2, 1);
	count += ft_putnstr_fd("0x", 2, 1);
	count += ft_putchars_fd('0', flags.precision - howmanychars_long(p, 16), 1);
	ft_putnbr_llll_base_fd(p, 16, 0, 1);
	return (count);
}

int	put_p_help_2(unsigned long p, t_info flags)
{
	int	count;
	int	len;

	count = 0;
	if (flags.precision > count)
		len = flags.precision;
	else
		len = count;
	if (flags.precision == -1)
	{
		count += ft_putnstr_fd("0x", 2, 1);
		count += ft_putchars_fd('0', flags.width - \
		howmanychars_long(p, 16) - 2, 1);
		count += ft_putnbr_llll_base_fd(p, 16, 0, 1);
	}
	else
	{
		count += ft_putchars_fd(' ', flags.width - count - len - 2, 1);
		count += ft_putnstr_fd("0x", 2, 1);
		count += ft_putchars_fd('0', flags.precision - \
		howmanychars_long(p, 16), 1);
		ft_putnbr_llll_base_fd(p, 16, 0, 1);
	}
	return (count);
}
