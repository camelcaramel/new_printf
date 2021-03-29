/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwik <donghwik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 22:25:15 by donghwik          #+#    #+#             */
/*   Updated: 2021/03/29 17:31:24 by donghwik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>


# include <stdio.h>

typedef struct	s_info
{
	int			flag;
	int			precision;
	int			width;
	int			print_zero;
}				t_info;

int		ft_printf(const char *fmts, ...);
int     print(const char **fmt, va_list *ap, int *result);
int     format_print(const char **fmt, va_list* ap, int *result);
int     symbol_switch(t_info info, const char **fmt, va_list* ap, int *result);

int		flag_proc(const char **format);
int		width_proc(const char **format, va_list *ap);
int		preci_proc(const char **format, va_list *ap, t_info *temp);


int		is_flag(const char c);
int		is_digit(const char c);
int		is_option(const char c);
int     ft_strlen(const char *s);
int     ft_numlen(long long n, int radix);

int     print_integer(long long n, t_info info, int radix, int *result);
int		print_leftize_integer(long long n, t_info info, int radix, int *result);
int		print_leftize_integer_lower(long long n, t_info info, int radix, int *result);
void    write_positive_integer(unsigned int n, int radix, int *result);
void	write_positive_integer_lower(unsigned int n, int radix, int *result);
int     print_integer_hex(long long n, t_info info, int radix, int *result);

void	write_char(const char c);
void	write_string(const char *s, int len);
int     print_char(const char c, t_info info);
int		print_leftize_char(const char c, t_info info);

int		min(int a, int b);
int     print_string(const char *s, t_info info);
int		print_leftize_string(const char *s, t_info info);

int     print_pointer(long long n, t_info info, int radix, int *result);
int		print_leftize_pointer(long long n, t_info info, int radix, int *result);
void	wc(const char c, int *result);
#endif
