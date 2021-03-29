#include "ft_printf.h"

void	wc(const char c, int *result)
{
	(*result)++;
	write(1, &c, 1);
}