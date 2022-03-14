#include "libftprintf.h"

int	ft_putchars_fd(char c, int n, int fd)
{
	int	count;

	count = 0;
	while (count < n)
	{
		write(fd, &c, 1);
		count++;
	}
	return (count);
}

int	ft_putnstr_fd(const char *s, int n, int fd)
{
	int	count;

	count = 0;
	while (s[count] && count < n)
	{
		write(fd, &s[count], 1);
		count++;
	}
	return (count);
}

int	ft_isfromset(char *s, char c)
{
	int	count;

	count = 0;
	if (s)
	{
		while (s[count])
		{
			if (s[count] == c)
				return (1);
			count++;
		}
	}
	return (0);
}

int	howmanychars(int n, int base)
{
	int	count;

	count = 0;
	if (n < 0)
		n = -n;
	while (n / base != 0)
	{
		count++;
		n /= base;
	}
	count++;
	return (count);
}
