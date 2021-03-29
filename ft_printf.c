/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwik <donghwik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 17:30:55 by donghwik          #+#    #+#             */
/*   Updated: 2021/03/29 17:25:01 by donghwik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_printf(const char *fmt, ...)
{
    va_list ap;
    int     result;

    result = 0;
    va_start(ap, fmt);
    result = print(&fmt, &ap, &result);
    va_end(ap);
    return (result);
}

int     print(const char **fmt, va_list *ap, int *result)
{
    while (**fmt)
    {
        if (**fmt == '%')
        {
            if(*((*fmt)+1) == '%')
                write_count(*((*fmt)++), result);
            else
            {
                (*fmt)++;
                format_print(fmt, ap, result);
            }
        }
        else
            write_count(**fmt, result);
        (*fmt)++;
    }
    return (1);
}

int     symbol_switch(t_info info, const char **fmt, va_list *ap, int *result)
{
    while (**fmt == ' ')
        (*fmt)++;
    if (**fmt == 'd' || **fmt == 'i')
        return (print_integer(va_arg(*ap, int), info, 10, result));
    else if (**fmt == 'u')
        return (print_integer(va_arg(*ap, unsigned int), info, 10, result));
    else if (**fmt == 'x')
        return (print_integer_hex(va_arg(*ap, int), info, 15, result));
    else if (**fmt == 'X')
        return (print_integer_hex(va_arg(*ap, int), info, 16, result));
    else if (**fmt == 'p')
    {
        write(1, &"0x1", 3);
        return (print_pointer((long long)va_arg(*ap, int *), info, 16, result));
    }
    else if (**fmt == 'c')
        return (print_char(va_arg(*ap, int), info));
    else if (**fmt == 's')
        return (print_string(va_arg(*ap, char *), info));
    else
        while (info.width > 0)
        {
            write_count(' ', result);
            info.width--;
        }
    return (1);
}

int     format_print(const char **format, va_list *ap, int *result)
{
    t_info temp;

    while (!is_digit(**format) && !is_flag(**format) 
                && !is_option(**format) && !(**format))
    {
        if (**format == ' ')
            write_count(**format, result);
        else
        {
            write_count(*((*format)++), result);
            break;
        }
        (*format)++;
    }
    temp.print_zero = 1;
    temp.flag = flag_proc(format);
    temp.width = width_proc(format, ap);
    temp.precision = preci_proc(format, ap, &temp);
    return (symbol_switch(temp, format, ap, result));
}
