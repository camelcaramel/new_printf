#include "ft_printf.h"

int     print_integer_hex(long long n, t_info info, int radix, int *result)
{
    int         	len;
	unsigned int	number;

	number = (unsigned int)n;
	len = ft_numlen(number, radix);
	if (info.flag == 0)
		return (print_leftize_integer(number, info, radix, result));
    while (info.width - info.precision > 0 && info.width - len > 0)
    {
        if (info.flag == 2)
			write_count(' ', result);
		else	
			write_count(' ', result);
        info.width--;
    }
    while (info.precision - len > 0)
    {
        info.precision--;
        write_count(' ', result);
    }
	if (radix == 15)
		write_positive_integer_lower(number, radix + 1, result);
	else
    	write_positive_integer(number, radix, result);
    return (1);
}