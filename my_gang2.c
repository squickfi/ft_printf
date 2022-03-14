#include "libftprintf.h"

unsigned int	ft_make_uns(int n)
{
	unsigned int	m;

	if (n >= 0)
		m = n;
	else
		m = -n;
	return (m);
}

int	ft_putnbr_base_fd(int n, int base, int reg, int fd)
{
	int				count;
	unsigned int	m;

	count = 0;
	m = ft_make_uns(n);
	if (m / base != 0)
	{
		count += ft_putnbr_base_fd(m / base, base, reg, fd);
	}
	if (m % base <= 9)
		ft_putchar_fd(m % base + '0', fd);
	else
	{
		if (reg)
			ft_putchar_fd(m % base + 'A', fd);
		else
			ft_putchar_fd(m % base + 'a', fd);
	}
	count++;
	return (count);
}

int	ft_putnbr_long_base_fd(unsigned int n, int base, int reg, int fd)
{
	int	count;

	count = 0;
	if (n / base != 0)
		count += ft_putnbr_long_base_fd(n / base, base, reg, fd);
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
