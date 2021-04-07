/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwik <donghwik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 17:30:55 by donghwik          #+#    #+#             */
/*   Updated: 2021/04/07 17:14:49 by donghwik         ###   ########.fr       */
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
            {
                wc1(*((*fmt)++), result);
                (*fmt)++;
            }
            else
            {
                (*fmt)++;
                format_print(fmt, ap, result);
                continue ;
            }
        }
        else
            wc1((*(*fmt)++), result);
    }
    return (1);
}

int     symbol_switch(t_info info, const char **fmt, va_list *ap, int *result)
{
    char    temp;

    while (**fmt == ' ')
        (*fmt)++;
    temp = **fmt;
    if (is_option(temp) || temp == '%')
        (*fmt)++;
    if (info.is_blank == 1)
        wc1(' ', result);
    if (temp == 'd' || temp == 'i')
        return (print_integer(va_arg(*ap, int), info, 10, result));
    else if (temp == 'u')
        return (print_integer(va_arg(*ap, unsigned int), info, 10, result));
    else if (temp == 'x')
        return (print_integer_hex(va_arg(*ap, int), info, 15, result));
    else if (temp == 'X')
        return (print_integer_hex(va_arg(*ap, int), info, 16, result));
    else if (temp == 'p')
        return (print_pointer((long long)va_arg(*ap, int *), info, 16, result));
    else if (temp == 'c')
        return (print_char(va_arg(*ap, int), info, result));
    else if (temp == 's')
        return (print_string(va_arg(*ap, char *), info, result));
    else if (temp == '%')
        return (print_char('%', info, result));
    else
    {
        if (info.is_blank == 1)
        {
            wc1(' ', result);
        }
        while (--info.width > 0)
        {
            wc1(' ', result);
        }            
    }

    return (1);
}

int     format_print(const char **format, va_list *ap, int *result)
{
    t_info temp;

    while (!is_digit(**format) && !is_flag(**format) 
                && !is_option(**format) && (**format))
    {
        if (**format == ' ')
            temp.is_blank = 1;
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
//     char *string = "|% *.5|\n";
//     ret_f = ft_printf(string, 5);
//     ret_o = printf(string, 5);
//     // ret_f = ft_printf("%5.0d*\n", 0);
//     // ret_o = printf("%5.0d*\n", ft_numlen(0, 10));
//     printf("return value of mine : %d\nreturn value of origin : %d\n", ret_f, ret_o);
//     return (0);
// }
