#include "libftprintf.h"

int	put_p(unsigned long p, t_info flags)
{
	int	count;

	count = 0;
	if (flags.sign)
	{
		count += ft_putnstr_fd("0x", 2, 1);
		count += ft_putchars_fd('0', flags.precision - \
		howmanychars_long(p, 16), 1);
		count += ft_putnbr_llll_base_fd(p, 16, 0, 1);
		count += ft_putchars_fd(' ', flags.width - count, 1);
	}
	else
	{
		if (flags.zero != '0')
			count += put_p_help(p, flags);
		else
			count += put_p_help_2(p, flags);
	}
	return (count);
}

int	put_p_str(t_info flags)
{
	int	count;

	count = 0;
	if (flags.sign)
	{
		count += ft_putnstr_fd("0x", 2, 1);
		count += ft_putchars_fd('0', flags.precision, 1);
		count += ft_putchars_fd(' ', flags.width - flags.precision - 2, 1);
	}
	else
	{
		count += ft_putchars_fd(' ', flags.width - flags.precision - 2, 1);
		count += ft_putnstr_fd("0x", 2, 1);
		count += ft_putchars_fd('0', flags.precision, 1);
	}
	return (count);
}

int	put_p_null_prec(t_info flags)
{
	int	count;

	count = 0;
	if (flags.sign)
	{
		count += ft_putnstr_fd("0x0", 3, 1);
		count += ft_putchars_fd(' ', flags.width - count, 1);
	}
	else
	{
		count += ft_putchars_fd(' ', flags.width - 3, 1);
		count += ft_putnstr_fd("0x0", 3, 1);
	}
	return (count);
}

int	ft_print_p(t_info flags, va_list argptr)
{
	unsigned long	p;
	int				count;

	count = 0;
	p = va_arg(argptr, unsigned long);
	if (!p && flags.precision >= 0)
	{
		count += put_p_str(flags);
		return (count);
	}
	if (!p)
	{
		count += put_p_null_prec(flags);
		return (count);
	}
	count += put_p(p, flags);
	return (count);
}

/*
int	put_p_str(char *p, t_info flags)
{
	int	count;

	count = 0;
	if (flags.sign)
	{
		count += ft_putnstr_fd("0x", 2, 1);
		count += ft_putnstr_fd(p, 100, 1);
		count += ft_putchars_fd(' ', flags.width - count, 1);
	}
	else
	{
		count = ft_strlen(p);
		count += ft_putchars_fd(' ', flags.width - count - 2, 1);
		count += ft_putnstr_fd("0x", 2, 1);
		ft_putnstr_fd(p, 100, 1);
	}
	return (count);
}

int	put_p_null_prec(t_info flags)
{
	int	count;

	count = 0;
	if (flags.sign)
	{
		count += ft_putnstr_fd("0x", 2, 1);
		count += ft_putchars_fd('0', flags.precision, 1);
		count += ft_putchars_fd(' ', flags.width - count, 1);
	}
	else
	{
		if (flags.precision >= 0)
			count = flags.precision;
		count += ft_putchars_fd(' ', flags.width - count - 2, 1);
		count += ft_putnstr_fd("0x", 2, 1);
		ft_putchars_fd('0', flags.precision, 1);
	}
	return (count);
}
*/