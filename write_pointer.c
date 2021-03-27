/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwik <donghwik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 17:30:37 by donghwik          #+#    #+#             */
/*   Updated: 2021/03/27 17:30:38 by donghwik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     print_pointer(long long n, t_info info, int radix)
{
    int         len;

    len = ft_numlen(n, radix);
	if (info.flag == 0)
	{
		print_leftize_pointer(n, info, radix);
		return (1);
	}
    while (info.width - info.precision > 0 && info.width - 11 > 0)
    {
		write(1, &" ", 1);
        info.width--;
    }
	while (9 - len > 0)
	{
		write(1, &"0", 1);
		len++;
	}
	write_positive_integer_lower(n, radix);
    return (1);
}

int		print_leftize_pointer(long long n, t_info info, int radix)
{
	int         len;

    len = ft_numlen(n, radix);
	while (9 - len > 0)
	{
		write(1, &"0", 1);
		len++;
	}
	write_positive_integer_lower(n, radix);
	while (info.width - 11 > 0)
	{
		write(1, &" ", 1);
		info.width--;
	}
	return (1);
}