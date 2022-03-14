#include "libftprintf.h"

int	ft_print_c(t_info flags, va_list argptr)
{
	unsigned char	c;
	int				count;

	count = 0;
	c = (unsigned char)va_arg(argptr, int);
	if (!flags.sign)
		count += ft_putchars_fd(flags.zero, flags.width - 1, 1);
	write(1, &c, 1);
	count++;
	if (flags.sign)
		count += ft_putchars_fd(' ', flags.width - 1, 1);
	return (count);
}

int	ft_print_s(t_info flags, va_list argptr)
{
	char	*s;
	int		count;
	int		len;

	count = 0;
	s = va_arg(argptr, char *);
	if (!s)
		s = "(null)";
	if (flags.precision < 0 || (int)ft_strlen(s) < flags.precision)
		len = (int)ft_strlen(s);
	else
		len = flags.precision;
	if (!flags.sign)
		count += ft_putchars_fd(flags.zero, flags.width - len, 1);
	ft_putnstr_fd(s, len, 1);
	count += len;
	if (flags.sign)
		count += ft_putchars_fd(' ', flags.width - len, 1);
	return (count);
}
