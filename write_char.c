#include "ft_printf.h"

void	write_char(const char c)
{
	write(1, &c, 1);
}

int     print_char(const char c, t_info info)
{
    int         len;

    len = 1;
	if (info.flag == 0)
	{
		return (print_leftize_char(c, info));
	}
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
	write_char(c);
    return (1);
}

int		print_leftize_char(const char c, t_info info)
{
	int         len;

    len = 1;
	while (info.precision - len > 0)
	{
		write(1, &"0", 1);
		info.precision--;
		info.width--;
	}
	write_char(c);
	while (info.width - len > 0)
	{
		write(1, &" ", 1);
		info.width--;
	}
	return (1);
}