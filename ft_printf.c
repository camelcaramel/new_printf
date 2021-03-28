/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwik <donghwik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 17:30:55 by donghwik          #+#    #+#             */
/*   Updated: 2021/03/28 10:32:56 by donghwik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_printf(const char *fmt, ...)
{
    va_list ap;
    int     result;

    va_start(ap, fmt);
    result = print(&fmt, &ap);
    va_end(ap);
    return (0);
}

int     print(const char **fmt, va_list *ap)
{
    while (**fmt)
    {
        if (**fmt == '%')
        {
            if(*((*fmt)+1) == '%')
                write(1, (*fmt)++, 1);
            else
            {
                (*fmt)++;
                format_print(fmt, ap);
            }
        }
        else
            write(1, *fmt, 1);
        (*fmt)++;
    }
    return (1);
}

int     symbol_switch(t_info info, const char **fmt, va_list *ap)
{
    while (**fmt == ' ')
        (*fmt)++;
    if (**fmt == 'd' || **fmt == 'i')
        return (print_integer(va_arg(*ap, int), info, 10));
    else if (**fmt == 'u')
        return (print_integer(va_arg(*ap, unsigned int), info, 10));
    else if (**fmt == 'x')
        return (print_integer_hex(va_arg(*ap, int), info, 16, 1));
    else if (**fmt == 'X')
        return (print_integer_hex(va_arg(*ap, int), info, 16, 0));
    else if (**fmt == 'p')
    {
        write(1, &"0x1", 3);
        return (print_pointer((long long)va_arg(*ap, int *), info, 16));
    }
    else if (**fmt == 'c')
        return (print_char(va_arg(*ap, int), info));
    else if (**fmt == 's')
        return (print_string(va_arg(*ap, char *), info));
    else
        while (info.width > 0)
        {
            write(1, &" ", 1);
            info.width--;
        }
    return (1);
}

int     format_print(const char **format, va_list *ap)
{
    t_info temp;

    while (!is_digit(**format) && !is_flag(**format) 
                && !is_option(**format) && !(**format))
    {
        if (**format == ' ')
            write(1, *format, 1);
        else
        {
            write(1, (*format)++, 1);
            break;
        }
        (*format)++;
    }
    temp.flag = flag_proc(format);
    temp.width = width_proc(format, ap);
    if (temp.width < 0)
    {
        temp.flag = 0;
        temp.width *= -1;
    }
    temp.precision = preci_proc(format, ap);
    return (symbol_switch(temp, format, ap));
}
