#include "ft_printf.h"

// int     print_integer_hex(long long n, t_info info, int radix, int *result)
// {
//     int         	len;
// 	unsigned int	number;

// 	number = (unsigned int)n;
// 	len = ft_numlen(number, radix);
// 	if (info.flag == 0)
// 		return (print_leftize_integer(number, info, radix, result));
//     while (info.width - info.precision > 0 && info.width - len > 0)
//     {
//         if (info.flag == 2)
// 			wc1(' ', result);
// 		else	
// 			wc1(' ', result);
//         info.width--;
//     }
//     while (info.precision - len > 0)
//     {
//         info.precision--;
//         wc1(' ', result);
//     }
// 	if (radix == 15)
// 		write_positive_integer_lower(number, radix + 1, result);
// 	else
//     	write_positive_integer(number, radix, result);
//     return (1);
// }

int     print_integer_hex(long long n, t_info info, int radix, int *result)
{
    int         len;
	unsigned int	number;

	number = (unsigned int)n;
	len = ft_numlen(number, radix);
	if (info.flag == 0)
		return (print_leftize_integer(number, info, radix, result));
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
    if (n == 0 && info.print_zero == 0)
    {
        if (info.precision == 0  && info.width == 0)
            info.width = 0;
        else if (info.precision == 0 && info.width != 0)
            wc1(' ', result);
        else if (info.flag <= 1 || info.width == 0)
            wc1('0', result);
    }
    else if (radix == 15)
		write_positive_integer_lower(number, radix + 1, result);
	else
    	write_positive_integer(number, radix, result);
    return (1);
}