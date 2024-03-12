/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukay <tkurukay@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 22:29:12 by tkurukay          #+#    #+#             */
/*   Updated: 2024/01/10 17:12:32 by tkurukay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

static int	ft_count_digits(unsigned long int nbr, int base)
{
	int	size;

	size = 1;
	while (nbr > 0)
	{
		size++;
		nbr /= base;
	}
	return (size);
}

int	ft_print_char(int c)
{
	return (write(1, &c, 1));
}

int	ft_print_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	while (str[i])
		if (ft_print_char(str[i++]) == -1)
			return (-1);
	return (i);
}

int	ft_print_hex(unsigned long num, char format, int len)
{
	char	*hex_result;
	int		i;

	hex_result = malloc(ft_count_digits(num, 16) + 1);
	if (!hex_result)
		return (-1);
	if (format == 'p')
		len += ft_print_str("0x");
	if (!num && len >= 0)
		len += ft_print_char('0');
	i = 0;
	while (num > 0 && len >= 0)
	{
		if (format == 'x' || format == 'p')
			hex_result[i++] = "0123456789abcdef"[num % 16];
		else
			hex_result[i++] = "0123456789ABCDEF"[num % 16];
		num /= 16;
	}
	hex_result[i] = '\0';
	while (i > 0 && len >= 0)
		len += ft_print_char(hex_result[--i]);
	free(hex_result);
	return (len);
}

int	ft_print_int(long num, int len)
{
	char	*dec_result;
	int		i;

	i = 0;
	if (num < 0)
	{
		len += ft_print_char('-');
		num = -num;
	}
	dec_result = malloc(ft_count_digits(num, 10) + 1);
	if (!dec_result)
		return (-1);
	if (!num)
		len += ft_print_char('0');
	while (num > 0 && len >= 0)
	{
		dec_result[i++] = "0123456789"[num % 10];
		num /= 10;
	}
	dec_result[i] = '\0';
	while (i > 0 && len >= 0)
		len += ft_print_char(dec_result[--i]);
	free(dec_result);
	return (len);
}
