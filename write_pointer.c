/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwik <donghwik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 17:30:37 by donghwik          #+#    #+#             */
/*   Updated: 2021/04/03 19:00:13 by donghwik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_pointer_numlen(unsigned long long n, int radix)
{
    unsigned long long ret;

    ret = 0;
    if (n == 0)
        return (1);
    while (n > 0)
    {
        ret++;
        n /= radix;
    }
    return (ret);
}

int     print_pointer(unsigned long long n, t_info info, int radix, int *result)
{
    int         len;

	if (n == (unsigned long long)NULL)
		n = 0;
    len = ft_pointer_numlen(n, radix) + 2;
	printf("width = %d, precision = %d, len = %d\n", info.width, info.precision, len);
	if (info.flag == 0)
	{
		print_leftize_pointer(n, info, radix, result);
		return (1);
	}
    while (info.width - len > 0 && info.width -  info.precision > 0)
    {
		wc1(' ', result);
        info.width--;
    }
	write(1, &"0x", 2);
	(*result) += 2;
	while (info.precision - len + 2 > 0)
	{
		wc1('0', result);
		info.precision--;
	}
	write_positive_integer_lower(n, radix, result);
    return (1);
}

int		print_leftize_pointer(unsigned long long n, t_info info, int radix, int *result)
{
	int         len;

    len = ft_pointer_numlen(n, radix) + 2;
	write(1, &"0x", 2);
	(*result) += 2;
	while (info.precision - len + 2 > 0)
	{
		wc1('0', result);
		info.precision--;
	}
	write_positive_integer_lower(n, radix, result);
	while (info.width - len > 0 && info.width - info.precision > 0)
	{
		wc1(' ', result);
		info.width--;
	}
	return (1);
}