/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwik <donghwik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 09:48:54 by donghwik          #+#    #+#             */
/*   Updated: 2021/04/08 11:23:57 by donghwik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_char(const char c, int *result)
{
	wc1(c, result);
}

int		print_char(const char c, t_info info, int *result)
{
	int		len;

	len = 1;
	if (info.flag == 0)
	{
		return (print_leftize_char(c, info, result));
	}
	while (info.width - info.precision > 0 && info.width - len > 0)
	{
		if (info.flag == 2)
			wc1('0', result);
		else
			wc1(' ', result);
		info.width--;
	}
	while (info.precision - len > 0)
	{
		info.precision--;
		wc1('0', result);
	}
	write_char(c, result);
	return (1);
}

int		print_leftize_char(const char c, t_info info, int *result)
{
	int		len;

	len = 1;
	while (info.precision - len > 0)
	{
		wc1('0', result);
		info.precision--;
		info.width--;
	}
	write_char(c, result);
	while (info.width - len > 0)
	{
		wc1(' ', result);
		info.width--;
	}
	return (1);
}
