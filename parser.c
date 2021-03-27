/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwik <donghwik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 17:30:26 by donghwik          #+#    #+#             */
/*   Updated: 2021/03/27 17:40:34 by donghwik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     flag_proc(const char **format)
{
    int     ret;

    ret = 1;
    while (**format == '0' || **format == '-' || **format == ' ') 
    {
        if (**format == '0')
        {
            ret = 2;
        }
        else if (**format == '-')
        {
            ret *= 0;
        }
        (*format)++;
    }
    return (ret);
}

int     width_proc(const char **format, va_list *ap)
{
    int     ret;

    ret = 0;
    while (**format == ' ')
        (*format)++;
    if (**format == '*')
    {
        ret = va_arg(*ap, int);
        return (ret);
    }
    while (is_digit(**format))
    {
        ret *= 10;
        ret += (**format) - '0';
        (*format)++;
    }
    return (ret); 
}

int     preci_proc(const char **format, va_list *ap)
{
    int     ret;

    ret = 0;
    while (**format == ' ')
        (*format)++;
    if (**format == '.')
    {
        (*format)++;
        while (**format == ' ')
            (*format)++;
        if (**format == '*')
        {
            ret = va_arg(*ap, int);
            return (ret);
        }
        while (is_digit(**format))
        {
            ret *= 10;
            ret += (**format) - '0';
            (*format)++;
        }
    }
    return (ret);
}