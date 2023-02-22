/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 11:11:43 by asarikha          #+#    #+#             */
/*   Updated: 2022/11/07 14:14:50 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	over_flow_handler(int sign)
{
	if (sign == 1)
		return (-1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long	num;
	int		sign;
	int		digit_found;

	num = 0;
	sign = 1;
	digit_found = 1;
	while (*str == ' ' || *str == '\n' || *str == '\r'
		|| *str == '\t' || *str == '\f' || *str == '\v')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+' )
		str++;
	while (*str && digit_found)
	{
		if (*str >= '0' && *str <= '9')
			num = num * 10 + *str - '0';
		else
			digit_found = 0;
		if (num < 0)
			return (over_flow_handler(sign));
		str++;
	}
	return (sign * num);
}
