/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhurpy <jhurpy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:43:21 by jeremy            #+#    #+#             */
/*   Updated: 2023/03/28 19:19:16 by jhurpy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <string.h>

char	*ft_itoa(int n);
int		ft_putchar(int c);
int		ft_putstr(char *s);
size_t	ft_strlen(const char *s);
size_t	ft_len_basep(unsigned long n, int base);
size_t	ft_len_basexu(unsigned int n, int base);


#endif
