/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 15:53:17 by jhurpy            #+#    #+#             */
/*   Updated: 2023/03/28 18:48:44 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The function ft_printf output according to a format as described below, write
output to stdout, the standart output stream.

Return the number of characters printed or negative value if an error occurs.
*/

#include "ft_printf.h"
#include "libft.h"
#include <stdarg.h>

int	ft_printf(const char *str, ...)
{
	size_t	len;
	va_list	args;

	va_start(args, str);
	if (str == NULL)
		return (0);
	len = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			len += dispatch(*(str + 1), &args);
			str++;
		}
		else
			len += ft_putchar(*str);
		str++;
	}
	va_end(args);
	return (len);
}

size_t	dispatch(int c, va_list *args)
{
	size_t	len;

	len = 0;
	if (c == 'd' || c == 'i')
		len += convert_int(va_arg(*args, int));
	else if (c == 'c')
		len += ft_putchar(va_arg(*args, int));
	else if (c == 's')
		len += ft_putstr(va_arg(*args, char *));
	else if (c == 'p')
		len += convert_digit(va_arg(*args, unsigned long), 'p');
	else if (c == 'u')
		len += ft_uitoa(va_arg(*args, unsigned int));
	else if (c == 'x')
		len += convert_digit(va_arg(*args, unsigned long), 'x');
	else if (c == 'X')
		len += convert_digit(va_arg(*args, unsigned long), 'X');
	else
		len += ft_putchar('%');
	return (len);
}
