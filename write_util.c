#include "ft_printf.h"

void	wc1(const char c, int *result)
{
	(*result)++;
	write(1, &c, 1);
}