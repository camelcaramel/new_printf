/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwik <donghwik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 17:30:33 by donghwik          #+#    #+#             */
/*   Updated: 2021/03/27 17:30:34 by donghwik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

void	write_string(const char *s, int len)
{
	const char *temp;

	temp = s;
	while (*temp)
		temp++;
	if (len != 0)
		write(1, s, min(len, temp - s - 1));
	else
		write(1, s, (temp - s -1));
}

int     print_string(const char *s, t_info info)
{
    int         len;

    len = ft_strlen(s);
	if (info.flag == 0)
	{
		return (print_leftize_string(s, info));
	}
    while (info.width - info.precision > 0)
    {
        if (info.flag == 2)
			write(1, &"0", 1);
		else	
			write(1, &" ", 1);
        info.width--;
    }
    while (info.precision - len > 0)
    {
        info.precision--;
        write(1, &"0", 1);
    }
	write_string(s, info.precision);
    return (1);
}

int		print_leftize_string(const char *s, t_info info)
{
	int         len;

    len = ft_strlen(s);
	while (info.precision - len > 0)
	{
		write(1, &"0", 1);
		info.precision--;
		info.width--;
	}
	write_string(s, info.precision);
	while (info.width - len > 0)
	{
		write(1, &" ", 1);
		info.width--;
	}
	return (1);
}