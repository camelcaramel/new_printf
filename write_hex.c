#include "ft_printf.h"

int     print_integer_hex(long long n, t_info info, int radix, short is_lower)
{
    int         	len;
	unsigned int	number;

	number = (unsigned int)n;
	len = ft_numlen(number, radix);
	if (info.flag == 0)
		return (print_leftize_integer(number, info, radix, is_lower));
    while (info.width - info.precision > 0 && info.width - len > 0)
    {
        if (info.flag == 2)
			write(1, &"0", 1);
		else	
			write(1, &" ", 1);
        info.width--;
    }
    while (info.precision - len > 0)
    {
        info.precision--;
        write(1, &"0", 1);
    }
	if (is_lower == 1)
		write_positive_integer_lower(number, radix);
	else
    	write_positive_integer(number, radix);
    return (1);
}