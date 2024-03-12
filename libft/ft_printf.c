/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukay <tkurukay@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:43:48 by idelemen          #+#    #+#             */
/*   Updated: 2024/03/06 17:56:17 by tkurukay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

static int	ft_check(char form)
{
	if (form == 'c' || form == 'd' || form == 'i' || form == 'u' || form == '%'
		|| form == 's' || form == 'x' || form == 'X' || form == 'p')
		return (1);
	return (0);
}

static int	ft_format(va_list arg, char format)
{
	if (format == 'c')
		return (ft_print_char(va_arg(arg, int)));
	else if (format == 's')
		return (ft_print_str(va_arg(arg, char *)));
	else if (format == 'p')
		return (ft_print_hex(va_arg(arg, unsigned long), format, 0));
	else if (format == 'd' || format == 'i')
		return (ft_print_int(va_arg(arg, int), 0));
	else if (format == 'u')
		return (ft_print_int(va_arg(arg, unsigned int), 0));
	else if (format == 'x' || format == 'X')
		return (ft_print_hex(va_arg(arg, unsigned int), format, 0));
	else if (format == '%')
		return (ft_print_char('%'));
	else
		return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		len;
	int		i;
	int		temp;

	len = 0;
	i = -1;
	va_start(arg, format);
	while (format[++i])
	{
		if (format[i] == '%' && ft_check(format[i + 1]))
		{
			temp = ft_format(arg, format[++i]);
			if (temp == -1)
				return (-1);
			len += temp;
		}
		else if (format[i] != '%' && ft_print_char(format[i]) == -1)
			return (-1);
		else if (format[i] != '%')
			len++;
	}
	va_end(arg);
	return (len);
}
