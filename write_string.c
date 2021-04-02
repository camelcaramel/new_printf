/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwik <donghwik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 17:30:33 by donghwik          #+#    #+#             */
/*   Updated: 2021/04/02 14:06:39 by donghwik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

void	write_string(const char *s, int len, int *result)
{
	const char	*temp;
	int			loop;
	int			i;

	i = 0;
	temp = s;
	while (*temp)
		temp++;
	if (len != 0)
		loop = min(len, temp - s);
	else
		loop = temp - s;
	while (loop > 0)
	{
		wc1(*(s + i), result);
		loop--;
		i++;
	}
}

int     print_string(const char *s, t_info info, int *result)
{
    int         len;

    len = ft_strlen(s);
	if (info.flag == 0)
	{
		return (print_leftize_string(s, info, result));
	}
    while (info.width - info.precision > 0 && info.width - len > 0)
    {
        // if (info.flag == 2)
		// 	wc1('0', result);
		// else	
			wc1(' ', result);
        info.width--;
    }
    // while (info.precision - len > 0)
    // {
    //     info.precision--;
    //     wc1('0', result);
    // }
	write_string(s, info.precision, result);
    return (1);
}

int		print_leftize_string(const char *s, t_info info, int *result)
{
	int         len;

    len = ft_strlen(s);
	// while (info.precision - len > 0)
	// {
	// 	wc1('0', result);
	// 	info.precision--;
	// 	info.width--;
	// }
	write_string(s, info.precision, result);
	while (info.width - len > 0)
	{
		wc1(' ', result);
		info.width--;
	}
	return (1);
}