/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwik <donghwik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 17:30:26 by donghwik          #+#    #+#             */
/*   Updated: 2021/04/07 16:59:38 by donghwik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     flag_proc(const char **format)
{
    int     ret;
    int     is_minus;

    ret = 1;
    is_minus = 1;
    while (**format == '0' || **format == '-' || **format == ' ') 
    {
        if (**format == '0')
        {
            ret = 2;
        }
        else if (**format == '-')
        {
            is_minus =  0;
        }
        (*format)++;
    }
    return (ret * is_minus);
}

int     width_proc(const char **format, va_list *ap, t_info *info)
{
    int     ret;

    ret = 0;
    info->is_va = 0;
    while (**format == ' ')
        (*format)++;
    while (**format == '*')
    {
        ret = va_arg(*ap, int);
        (*format)++;
        info->is_va = 1;
        if (ret < 0)
        {
            info->flag = 0;
            ret *= -1;
        }
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

int     preci_proc(const char **format, va_list *ap, t_info *temp)
{
    int     ret;
    int     sign;

    ret = 0;
    sign = 1;
    temp->is_dot = 0;
    while (**format == ' ')
        (*format)++;
    if (**format == '.')
    {
        temp->print_zero = 0;
        temp->is_dot = 1;
        (*format)++;
        while (**format == ' ')
            (*format)++;
        if (**format == '*')
        {
            ret = va_arg(*ap, int);
            (*format)++;
            if (temp->is_va == 1 && temp->flag == 2 && ret >= 0)
                temp->flag = 1;
            if (ret < 0)
            {
                temp->print_zero = 1;
                // chagne point
                return (ret);
            }
            if (ret == 0)
                temp->print_zero = 0;
            return (ret);
        }
        if (**format == '-')
            sign = -1;
        while (is_digit(**format))
        {
            ret *= 10;
            ret += (**format) - '0';
            (*format)++;
        }
    }
    if (sign * ret < 0)
    {
        temp->width = ret;
        temp->flag = 0;
        temp->print_zero = 0;
        return (0);
    }
    if (ret > 0)
        temp->print_zero = 1;
    return (sign * ret);
}