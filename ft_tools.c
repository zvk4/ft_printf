/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarali <zkarali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 13:36:25 by zkarali           #+#    #+#             */
/*   Updated: 2025/07/06 15:00:23 by zkarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_char(char c)
{
	return (write(1, &c, 1));
}

int	ft_str(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_nbr(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		i += write(1, "-2147483648", 11);
		return (i);
	}
	if (n < 0)
	{
		i += ft_char('-');
		n = -n;
	}
	if (n > 9)
		i += ft_nbr(n / 10);
	i += ft_char((n % 10) + '0');
	return (i);
}

int	ft_unsigned(unsigned int n)
{
	char	buffer[10];
	int		i;
	int		len;

	len = 0;
	if (n == 0)
	{
		len += write(1, "0", 1);
		return (len);
	}
	i = 0;
	while (n > 0)
	{
		buffer[i++] = (n % 10) + '0';
		n /= 10;
	}
	while (i--)
		len += write(1, &buffer[i], 1);
	return (len);
}

int	ft_hex(unsigned int n, char c)
{
	int	i;

	i = 0;
	if (n >= 16)
		i += ft_hex(n / 16, c);
	if (c == 'X')
		i += write(1, &"0123456789ABCDEF"[n % 16], 1);
	else if (c == 'x')
		i += write(1, &"0123456789abcdef"[n % 16], 1);
	return (i);
}

int	ft_pointer(void *p)
{
	int				i;
	unsigned long	ptr;

	i = 0;
	ptr = (unsigned long)p;
	i += write(1, "0x", 2);
	i += ft_hex(ptr, 'x');
	return (i);
}
