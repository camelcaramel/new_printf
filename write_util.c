#include "ft_printf.h"

void	write_count(const char c, int *result)
{
	(*result)++;
	write(1, &c, 1);
}