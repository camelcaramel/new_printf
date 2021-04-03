/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwik <donghwik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 17:30:55 by donghwik          #+#    #+#             */
/*   Updated: 2021/04/03 16:34:45 by donghwik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_printf(const char *fmt, ...)
{
    va_list ap;
    int     result;

    result = 0;
    if (fmt == NULL)
    {
        write_string("(null)", 6, &result);
        return (result);
    }
    va_start(ap, fmt);
    print(&fmt, &ap, &result);
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
                wc1(*((*fmt)++), result);
            else
            {
                (*fmt)++;
                format_print(fmt, ap, result);
            }
        }
        else
            wc1(**fmt, result);
        (*fmt)++;
    }
    return (1);
}

int     symbol_switch(t_info info, const char **fmt, va_list *ap, int *result)
{
    while (**fmt == ' ' && (**fmt))
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
        return (print_pointer((long long)va_arg(*ap, int *), info, 16, result));
    else if (**fmt == 'c')
        return (print_char(va_arg(*ap, int), info, result));
    else if (**fmt == 's')
        return (print_string(va_arg(*ap, char *), info, result));
    else if (**fmt == '%')
        return (print_char('%', info, result));
    else
        while (info.width > 0)
        {
            wc1(' ', result);
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
            wc1(**format, result);
        else
        {
            wc1(*((*format)++), result);
            break;
        }
        (*format)++;
    }
    temp.print_zero = 1;
    temp.flag = flag_proc(format);
    temp.width = width_proc(format, ap, &temp);
    temp.precision = preci_proc(format, ap, &temp);
    return (symbol_switch(temp, format, ap, result));
}


// int main(void)
// {
//     //int n = 123;
//     // int k = 0;
//     // char *s = "hello world, %5%";
//     int ret_f = 0;
//     int ret_o = 0;
//     char *string = "hello world";
//     ret_f = ft_printf("%-020d\n", 123);
//     ret_o = printf("%-020d\n", 123);
//     // ret_f = ft_printf("%5.0d*\n", 0);
//     // ret_o = printf("%5.0d*\n", ft_numlen(0, 10));
//     printf("return value of mine : %d\nreturn value of origin : %d\n", ret_f, ret_o);
//     return (0);
// }
