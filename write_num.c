/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwik <donghwik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 17:30:30 by donghwik          #+#    #+#             */
/*   Updated: 2021/04/14 14:05:31 by donghwik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_positive_integer(unsigned long long n, int radix, int *result)
{
	if (n / radix == 0)
	{
		wc1("0123456789ABCDEF"[n % radix], result);
		return ;
	}
	write_positive_integer(n / radix, radix, result);
	wc1("0123456789ABCDEF"[n % radix], result);
}

void	write_positive_integer_lower(unsigned long long n,
										int radix, int *result)
{
	if (n / radix == 0)
	{
		wc1("0123456789abcdef"[n % radix], result);
		return ;
	}
	write_positive_integer_lower(n / radix, radix, result);
	wc1("0123456789abcdef"[n % radix], result);
}

int		print_integer(long long n, t_info info, int radix, int *result)
{
	int		len;
	int		is_write_sign;

	len = ft_numlen(n, radix);
	is_write_sign = 0;
	if (info.flag == 0)
		return (print_leftize_integer(n, info, radix, result));
	if (n < 0)
		info.width--;
	if (n < 0 && info.flag == 2 && !(info.is_dot == 1 && info.precision > 0))
		wc1('-', result);
	width_handling(&info, len, result);
	if (n < 0 && (n *= -1) > 0 && !(info.flag == 2
					&& !(info.is_dot == 1 && info.precision > 0)))
	{
		wc1('-', result);
	}
	while (info.precision - len > 0)
	{
		info.precision--;
		wc1('0', result);
	}
	if (print_zero_handler(n, info, result))
		write_positive_integer(n, radix, result);
	return (1);
}

int		print_leftize_integer(long long n, t_info info, int radix, int *result)
{
	int			len;

	len = ft_numlen(n, radix);
	if (n < 0)
		info.width--;
	if (n < 0 && (n *= -1) > 0)
		wc1('-', result);
	while (info.precision - len > 0)
	{
		wc1('0', result);
		info.precision--;
		info.width--;
	}
	if (print_zero_handler(n, info, result))
	{
		if (radix == 15)
			write_positive_integer_lower(n, radix + 1, result);
		else
			write_positive_integer(n, radix, result);
	}
	while ((info.width--) - len > 0)
		wc1(' ', result);
	return (1);
}

int		print_leftize_integer_lower(long long n, t_info info,
												int radix, int *result)
{
	int		len;

	len = ft_numlen(n, radix);
	if (n < 0)
		info.width--;
	if (n < 0 && (n *= -1) > 0)
		wc1('-', result);
	while (info.precision - len > 0)
	{
		wc1('0', result);
		info.precision--;
		info.width--;
	}
	if (!info.print_zero && n == 0)
		wc1(' ', result);
	write_positive_integer_lower(n, radix, result);
	while (info.width - len > 0)
	{
		wc1(' ', result);
		info.width--;
	}
	return (1);
}
