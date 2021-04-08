/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwik <donghwik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 17:30:33 by donghwik          #+#    #+#             */
/*   Updated: 2021/04/08 11:49:44 by donghwik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_string(const char *s, int len, int *result)
{
	const char	*temp;
	int			loop;
	int			i;

	i = 0;
	temp = s;
	while (*temp)
		temp++;
	if (len < 0)
		loop = temp - s;
	else if (len != 0)
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

int		print_string(char *s, t_info info, int *result)
{
	int		len;

	if (s == NULL)
		s = "(null)";
	len = ft_strlen(s);
	if (info.is_dot == 1 && info.precision == 0)
	{
		width_print(info.width, 0, result, info.flag);
		return (1);
	}
	if (info.is_dot != 1 || info.precision < 0)
		info.precision = len;
	if (info.flag == 0)
	{
		return (print_leftize_string(s, info, result));
	}
	len = min(info.precision, len);
	if (len < 0)
		len = 0;
	width_print(info.width, len, result, info.flag);
	write_string(s, info.precision, result);
	return (1);
}

void	width_print(int width, int len, int *result, int flag)
{
	while (width - len > 0)
	{
		if (flag == 2)
			wc1('0', result);
		else
			wc1(' ', result);
		width--;
	}
}

int		print_leftize_string(const char *s, t_info info, int *result)
{
	int		len;

	len = ft_strlen(s);
	if (info.precision < 0)
		info.precision = len;
	write_string(s, info.precision, result);
	if (info.is_dot != 1)
		info.precision = len;
	len = min(len, info.precision);
	if (len < 0)
		len *= -1;
	while (info.width - len > 0)
	{
		wc1(' ', result);
		info.width--;
	}
	return (1);
}
