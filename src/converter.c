/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 02:52:21 by jhurpy            #+#    #+#             */
/*   Updated: 2023/03/28 18:14:01 by jhurpy           ###   ########.fr       */
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

size_t	convert_un_int(unsigned int c)
{
	size_t	len;
	char	*ptr;

	ptr = ft_u_itoa(c);
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
