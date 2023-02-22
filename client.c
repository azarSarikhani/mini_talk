/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 11:11:43 by asarikha          #+#    #+#             */
/*   Updated: 2023/02/21 12:46:57 by asarikha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_confirm(int signal)
{
	static int	sent_char = 0;

	if (signal == SIGUSR2)
	{
		ft_printf("\033[0;32mconfirmation recieved, server\033[0;32m", 1);
		ft_printf("\033[0;32m recieved %d characters.\n\033[0;32m", sent_char);
	}
	if (signal == SIGUSR1)
		sent_char++;
}

void	ft_send_bits(int pid, char c, size_t len)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(150 + (len % 50) + (len % 250) + (len % 1250));
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int				pid;
	int				i;
	unsigned int	len;

	i = 0;
	if (argc == 3)
	{
		len = ft_strlen(argv[2]);
		pid = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			signal(SIGUSR1, ft_confirm);
			signal(SIGUSR2, ft_confirm);
			ft_send_bits(pid, argv[2][i], len);
			i++;
		}
		ft_send_bits(pid, '\0', len);
		ft_send_bits(pid, '\n', len);
	}
	else
	{
		ft_printf("\033[91mwrong format. Try: ./client [PID] [MESSAGE]\033[0m\n");
		return (1);
	}
	return (0);
}
