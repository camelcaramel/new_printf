/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwik <donghwik@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 22:25:15 by donghwik          #+#    #+#             */
/*   Updated: 2021/04/14 14:10:25 by donghwik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_info
{
	int			flag;
	int			precision;
	int			width;
	int			print_zero;
	int			is_va;
	int			is_dot;
	int			is_blank;
	int			is_flag_modified;
}				t_info;

int				ft_printf(const char *fmts, ...);
int				print(const char **fmt, va_list *ap, int *result);
int				format_print(const char **fmt, va_list *ap, int *result);
int				symbol_switch_number(t_info info, const char **fmt,
						va_list *ap, int *result);
int				symbol_switch_other(t_info info, const char temp,
										va_list *ap, int *result);

int				flag_proc(const char **format);
int				width_proc(const char **format, va_list *ap, t_info *info);
int				preci_proc(const char **format, va_list *ap, t_info *temp);
int				preci_get_va(const char **format, va_list *ap, t_info *temp);
int				return_preci(int ret, int sign, t_info *info);

int				is_flag(const char c);
int				is_digit(const char c);
int				is_option(const char c);
int				ft_strlen(const char *s);
int				ft_numlen(long long n, int radix);

int				print_integer(long long n, t_info info, int radix, int *result);
int				print_leftize_integer(long long n, t_info info,
										int radix, int *result);
int				print_leftize_integer_lower(long long n,
						t_info info, int radix, int *result);
void			write_positive_integer(unsigned long long n, int radix,
										int *result);
void			write_positive_integer_lower(unsigned long long n,
								int radix, int *result);

int				print_integer_hex(long long n, t_info info,
									int radix, int *result);
void			hex_width_handling(t_info *info, int len, int *result);

void			write_char(const char c, int *result);
int				print_char(const char c, t_info info, int *result);
int				print_leftize_char(const char c, t_info info, int *result);

void			write_string(const char *s, int len, int *result);
int				print_string(char *s, t_info info, int *result);
int				print_leftize_string(const char *s, t_info info, int *result);
void			width_print(int width, int len, int *result, int flag);

int				print_pointer(unsigned long long n, t_info info,
								int radix, int *result);
int				print_leftize_pointer(unsigned long long n, t_info info,
						int radix, int *result);
int				ft_pointer_numlen(unsigned long long n, int radix);

int				min(int a, int b);
void			wc1(const char c, int *result);
int				print_zero_handler(int n, t_info info, int *result);
int				width_handling(t_info *info, int len, int *result);
#endif
