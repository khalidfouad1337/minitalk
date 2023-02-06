/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khalid <khalid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:46:21 by kfouad            #+#    #+#             */
/*   Updated: 2023/02/06 15:35:58 by khalid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	pawer_two(int n)
{
	int	i;
	int	result;

	i = 0;
	result = 1;
	while (i++ < n)
		result *= 2;
	return (result);
}

unsigned char	ft_byte_to_char(char *byte)
{
	int				i;
	unsigned char	result;

	result = 0;
	i = 0;
	while (i < 8)
	{
		if (byte[i] == '1')
			result += pawer_two(i);
		i++;
	}
	return (result);
}

void	handler(int sig, siginfo_t *info, void *p)
{
	static int		nbr_bit = 0;
	static char		byte[8];
	unsigned char	c;

	(void)p;
	(void)info;
	if (sig == SIGUSR1)
		byte[nbr_bit] = '0';
	else
		byte[nbr_bit] = '1';
	nbr_bit++;
	if (nbr_bit == 8)
	{
		c = ft_byte_to_char(byte);
		write (1, &c, 1);
		nbr_bit = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	pid = getpid();
	ft_printf("PID : %d\n", pid);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	while (1)
	{
		pause();
	}
	return (0);
}
