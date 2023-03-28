/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 02:52:21 by jhurpy            #+#    #+#             */
/*   Updated: 2023/03/28 19:20:06 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
The function change_int pass int to str, count the lenght and print it.
The function change_un_int pass unsigned int to str,
count the lenght and print it.
The function change_to_hexa pass unsigned int to is hexadecimal str,
count the lenght and print it.
*/

#include "ft_printf.h"
#include "libft.h"

size_t	convert_int(int c)
{
	size_t	len;
	char	*ptr;

	ptr = ft_itoa(c);
	len = ft_strlen(ptr);
	ft_putstr(ptr);
	free (ptr);
	return (len);
}

size_t	convert_digit(unsigned long long c, int f)
{
	size_t	len;

	len = 0;
	if (f == 'p')
		len += write (1, "0x", 2);
	if (c == '0')
	{
		ft_putchar('0');
		len++;
	}
	else if (f == 'p')
		len += ft_litohexa(c, f);
	else
		len += ft_uitohexa(c, f);
	return (len);
}

size_t	ft_litohexa(unsigned long long c, const int f)
{
	size_t			len;

	len = ft_len_basep(c, 16);
	if (c >= 16)
	{
		ft_litohexa(c / 16, f);
		ft_litohexa(c % 16, f);

	}
	else if (c <= 9)
		ft_putchar(c + '0');
	else
	{
		if (f == 'x' || f == 'p')
			ft_putchar(c - 10 + 'a');
		else
			ft_putchar(c - 10 + 'A');
	}
	return(len);
}

size_t	ft_uitohexa(unsigned int c, const int f)
{
	size_t			len;

	len = ft_len_basexu(c, 16);
	if (c >= 16)
	{
		ft_uitohexa(c / 16, f);
		ft_uitohexa(c % 16, f);

	}
	else if (c <= 9)
		ft_putchar(c + '0');
	else
	{
		if (f == 'x' || f == 'p')
			ft_putchar(c - 10 + 'a');
		else
			ft_putchar(c - 10 + 'A');
	}
	return(len);
}

size_t	ft_uitoa(unsigned int n)
{
	size_t	len;

	len = ft_len_basexu(n, 10);
	if (n >= 10)
	{
		ft_uitoa(n / 10);
		ft_uitoa(n % 10);
	}
	else
		ft_putchar(n + '0');
	return (len);
}
