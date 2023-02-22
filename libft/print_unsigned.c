/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 11:11:43 by asarikha          #+#    #+#             */
/*   Updated: 2023/01/30 16:09:56 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	unsigned_len(unsigned int n)
{
	int	print_len;

	print_len = 0;
	while (n != 0)
	{
		print_len++;
		n = n / 10;
	}
	return (print_len);
}

static	void	put_unsigned(unsigned int n)
{
	if (n < 10)
	{
		print_char(n + '0');
	}
	else
	{
		put_unsigned(n / 10);
		put_unsigned(n % 10);
	}
}

int	print_unsigned(unsigned int n)
{
	int	print_len;

	print_len = 0;
	if (n == 0)
		print_len += write(1, "0", 1);
	else
		put_unsigned(n);
		print_len += unsigned_len(n);
	return (print_len);
}
