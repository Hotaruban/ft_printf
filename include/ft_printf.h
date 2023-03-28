/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:09:21 by jhurpy            #+#    #+#             */
/*   Updated: 2023/03/28 18:56:05 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
size_t	dispatch(int c, va_list *args);
/*
The converter file call every function need to convert args.
*/
size_t	convert_int(int c);
size_t	convert_digit(unsigned long long c, int f);
size_t	len_numb_hexa(unsigned int n);
size_t	ft_litohexa(unsigned long long c, const int f);
size_t	ft_uitohexa(unsigned int c, const int f);
size_t	ft_uitoa(unsigned int n);

#endif
