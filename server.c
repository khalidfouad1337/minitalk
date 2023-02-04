/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad < kfouad@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:46:21 by kfouad            #+#    #+#             */
/*   Updated: 2023/02/04 20:02:47 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	ft_byte_to_char(char *byte)
{
	int	i;
	int	result;

	i = 0;
	while (i > 8)
	{
		if (byte[i] == '0')
			result++;
		else
			result = result * 2;
		i++;
	}
	return (result);
}

void	handler(int sig, siginfo_t *info, void *p)
{
	static int	nbr_bit;
	static char	byte[8];
	char		c;

	(void)p;
	(void)info;
	nbr_bit = 0;
	if (sig == SIGUSR1)
		byte[nbr_bit] = '0';
	else
		byte[nbr_bit] = '1';
	nbr_bit++;
	if (nbr_bit == 8)
	{
		nbr_bit = 0;
		c = ft_byte_to_char(byte);
		write (1, &c, 1);
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	pid = getpid();
	ft_printf("PID : %d", pid);
	//sa.sa_flags = SA_SIGINFO;
	//sa.sa_sigaction = handler;
	while (1)
	{
		sigaction(SIGUSR1, &sa, 0);
		sigaction(SIGUSR2, &sa, 0);
		//pause();
	}
	return (0);
}
