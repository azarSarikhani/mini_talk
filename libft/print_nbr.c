/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 11:11:43 by asarikha          #+#    #+#             */
/*   Updated: 2023/01/30 16:09:46 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	nbr_len(int nb)
{
	int	print_len;

	print_len = 0;
	if (nb == -2147483648)
	{	
		print_len += 2;
		nb = 147483648;
	}
	if (nb < 0)
	{
		print_len += 1;
		nb = -nb;
	}
	if (nb == 0)
	{
		print_len += 1;
	}
	while (nb != 0)
	{
		print_len++;
		nb = nb / 10;
	}
	return (print_len);
}

static	void	put_nbr(int nb)
{
	if (nb == -2147483648)
	{	
		write(1, "-2", 2);
		nb = 147483648;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb < 10)
	{
		print_char(nb + '0');
	}
	else
	{
		put_nbr(nb / 10);
		put_nbr(nb % 10);
	}
}

int	print_nbr(int nb)
{
	int	print_len;

	print_len = 0;
	put_nbr(nb);
	print_len = nbr_len(nb);
	return (print_len);
}
