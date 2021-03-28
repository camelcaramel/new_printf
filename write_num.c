/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwik <donghwik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 17:30:30 by donghwik          #+#    #+#             */
/*   Updated: 2021/03/28 12:09:40 by donghwik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    write_positive_integer(unsigned int n, int radix)
{
    if (n / radix == 0)
    {
        write(1, &"0123456789ABCDEF"[n % radix], 1);
        return ;
    }
    write_positive_integer(n / radix, radix);
    write(1, &"0123456789ABCDEF"[n % radix], 1);
}

void	write_positive_integer_lower(unsigned int n, int radix)
{
	if (n / radix == 0)
    {
        write(1, &"0123456789abcdef"[n % radix], 1);
        return ;
    }
    write_positive_integer_lower(n / radix, radix);
    write(1, &"0123456789abcdef"[n % radix], 1);
}

int     print_integer(long long n, t_info info, int radix)
{
    int         len;

    len = ft_numlen(n, radix);
	if (info.flag == 0)
		return (print_leftize_integer(n, info, radix, 0));
    if (n < 0)
        info.width--;
    while (info.width - info.precision > 0 && info.width - len > 0)
    {
        if (info.flag == 2)
			write(1, &"0", 1);
		else	
			write(1, &" ", 1);
        info.width--;
    }
    if (n < 0 && (n *= -1) > 0)
        write(1, &"-", 1);
    while (info.precision - len > 0)
    {
        info.precision--;
        write(1, &"0", 1);
    }
    if (n == 0 && info.print_zero == 0)
        write(1, &" ", 1);
    else
        write_positive_integer(n, radix);
    return (1);
}

int		print_leftize_integer(long long n, t_info info, int radix, short is_lower)
{
	int         len;

    len = ft_numlen(n, radix);
	if (n < 0)
		info.width--;
	while (info.precision - len > 0)
	{
		write(1, &"0", 1);
		info.precision--;
		info.width--;
	}
	if (n < 0 && (n *= -1) > 0)
        write(1, &"-", 1);
    if (!info.print_zero)
        write(1, &" ", 1);
    else if (is_lower == 1)
        write_positive_integer_lower(n, radix);
    else
        write_positive_integer(n, radix);
	while (info.width - len > 0)
	{
		write(1, &" ", 1);
		info.width--;
	}
	return (1);
}
