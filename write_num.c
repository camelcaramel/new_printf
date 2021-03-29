/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwik <donghwik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 17:30:30 by donghwik          #+#    #+#             */
/*   Updated: 2021/03/29 17:20:58 by donghwik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    write_positive_integer(unsigned int n, int radix, int *result)
{
    if (n / radix == 0)
    {
        write_count("0123456789ABCDEF"[n % radix], result);
        return ;
    }
    write_positive_integer(n / radix, radix, result);
    write_count("0123456789ABCDEF"[n % radix], result);
}

void	write_positive_integer_lower(unsigned int n, int radix, int *result)
{
	if (n / radix == 0)
    {
        write_count("0123456789abcdef"[n % radix], result);
        return ;
    }
    write_positive_integer_lower(n / radix, radix, result);
    write_count("0123456789abcdef"[n % radix], result);
}

int     print_integer(long long n, t_info info, int radix, int *result)
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
			write_count('0', result);
		else	
			write_count(' ', result);
        info.width--;
    }
    if (n < 0 && (n *= -1) > 0)
        write_count(' ', result);
    while (info.precision - len > 0)
    {
        info.precision--;
        write_count('0', result);
    }
    if (n == 0 && info.print_zero == 0)
        write_count(' ', result);
    else
        write_positive_integer(n, radix, result);
    return (1);
}

int		print_leftize_integer(long long n, t_info info, int radix, int *result)
{
	int         len;

    len = ft_numlen(n, radix);
	if (n < 0)
		info.width--;
	while (info.precision - len > 0)
	{
		write_count('0', result);
		info.precision--;
		info.width--;
	}
	if (n < 0 && (n *= -1) > 0)
        write_count('-', result);
    if (!info.print_zero && n == 0)
        write_count(' ', result);
    if (radix == 15)
        write_positive_integer_lower(n, radix, result);
    else
        write_positive_integer(n, radix, result);
	while (info.width - len > 0)
	{
		write_count(' ', result);
		info.width--;
	}
	return (1);
}

int		print_leftize_integer_lower(long long n, t_info info, int radix, int *result)
{
	int         len;

    len = ft_numlen(n, radix);
	if (n < 0)
		info.width--;
	while (info.precision - len > 0)
	{
		write_count('0', result);
		info.precision--;
		info.width--;
	}
	if (n < 0 && (n *= -1) > 0)
        write_count('-', result);
    if (!info.print_zero && n == 0)
        write_count(' ', result);
    write_positive_integer_lower(n, radix, result);
	while (info.width - len > 0)
	{
		write_count(' ', result);
		info.width--;
	}
	return (1);
}
