/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 11:11:43 by asarikha          #+#    #+#             */
/*   Updated: 2023/01/30 16:13:41 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	formatter(const char format_specifier, va_list arg_pram)
{
	int				print_len;
	unsigned int	i;

	i = 0;
	print_len = 0;
	if (format_specifier == 'c')
		print_len += print_char(va_arg(arg_pram, int));
	if (format_specifier == 's')
		print_len += print_str(va_arg(arg_pram, char *));
	if (format_specifier == 'd' || format_specifier == 'i')
		print_len += print_nbr(va_arg(arg_pram, int));
	if (format_specifier == 'p')
		print_len += print_ptr(va_arg(arg_pram, unsigned long long));
	if (format_specifier == 'x' || format_specifier == 'X')
		print_len += print_hex(va_arg(arg_pram, unsigned int),
				format_specifier);
	if (format_specifier == 'u')
		print_len += print_unsigned(va_arg(arg_pram, unsigned int));
	if (format_specifier == '%')
		print_len += write(1, "%", 1);
	return (print_len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		print_len;
	va_list	arg_pram;

	i = 0;
	print_len = 0;
	va_start(arg_pram, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] != 0)
			{
				i++;
				print_len += formatter(str[i], arg_pram);
			}
		}
		else
			print_len += print_char(str[i]);
		i++;
	}
	va_end(arg_pram);
	return (print_len);
}
