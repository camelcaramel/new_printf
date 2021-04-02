/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwik <donghwik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 17:30:37 by donghwik          #+#    #+#             */
/*   Updated: 2021/04/02 15:28:16 by donghwik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     print_pointer(long long n, t_info info, int radix, int *result)
{
    int         len;

    len = ft_numlen(n, radix);
	if (info.flag == 0)
	{
		print_leftize_pointer(n, info, radix, result);
		return (1);
	}
    while (info.width - info.precision > 0 && info.width - len > 0)
    {
		wc1(' ', result);
        info.width--;
    }
	// while (9 - len > 0)
	// {
	// 	wc1('0', result);
	// 	len++;
	// }
	write_positive_integer_lower(n, radix, result);
    return (1);
}

int		print_leftize_pointer(long long n, t_info info, int radix, int *result)
{
	int         len;

    len = ft_numlen(n, radix);
	// while (9 - len > 0)
	// {
	// 	wc1('0', result);
	// 	len++;
	// }
	write_positive_integer_lower(n, radix, result);
	while (info.width - len > 0)
	{
		wc1(' ', result);
		info.width--;
	}
	return (1);
}