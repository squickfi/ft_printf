#include "libftprintf.h"

int	ft_parse_pricision(char *s, t_info *flags, va_list argptr)
{
	int	count;

	count = 1;
	if (s[count] == '*')
	{
		flags->precision = va_arg(argptr, int);
		if (flags->precision < 0)
			flags->precision = -1;
		count++;
		return (count);
	}
	flags->precision = ft_atoi(s + 1);
	while (ft_isdigit(s[count]))
		count++;
	return (count);
}

int	ft_parse_width(char *s, t_info *flags, va_list argptr)
{
	int	count;

	count = 0;
	if (s[count] == '*')
	{
		flags->width = va_arg(argptr, int);
		count++;
		if (flags->width < 0)
		{
			flags->width = -flags->width;
			flags->sign = 1;
			flags->zero = ' ';
		}
		if (s[count] == '.')
			count += ft_parse_pricision(s + count, flags, argptr);
		return (count);
	}
	flags->width = ft_atoi(s);
	while (ft_isdigit(s[count]))
		count++;
	if (s[count] == '.')
		count += ft_parse_pricision(s + count, flags, argptr);
	return (count);
}

int	ft_parse_signes(char *s, t_info *flags)
{
	int	count;

	count = 0;
	while (s[count] == '-' || s[count] == '0')
	{
		if (s[count] == '-')
		{
			flags->sign = 1;
			count++;
		}
		if (s[count] == '0')
		{
			flags->zero = '0';
			count++;
		}
	}
	if (flags->sign == 1)
		flags->zero = ' ';
	return (count);
}

int	ft_parse_flags(char *s, t_info *flags, va_list argptr)
{
	int	count;
	int	temp;

	count = 0;
	temp = ft_parse_signes(s, flags);
	count += temp;
	s += temp;
	temp = ft_parse_width(s, flags, argptr);
	count += temp;
	s += temp;
	if (ft_isfromset("cpsdiuxX%%", *s))
	{
		flags->specifier = *s;
		return (count + 1);
	}
	else
		return (0);
}
