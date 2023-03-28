/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_litohexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:12:29 by jhurpy            #+#    #+#             */
/*   Updated: 2023/03/28 18:23:49 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
