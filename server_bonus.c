/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad <kfouad@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 19:37:12 by kfouad            #+#    #+#             */
/*   Updated: 2023/03/13 17:27:04 by kfouad           ###   ########.fr       */
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

int	ft_cas_error(int *client_pid, int *bit, int *i, int pid)
{
	*i = 0;
	if (*client_pid != pid)
	{
		*bit = 0;
		*client_pid = pid;
		return (1);
	}
	return (0);
}

void	handler(int sig, siginfo_t *info, void *p)
{
	static int		nbr_bit;
	static char		byte[8];
	static int		client_pid;
	unsigned char	c;
	int				i;

	(void)p;
	if (client_pid == 0)
		client_pid = info->si_pid;
	if (ft_cas_error(&client_pid, &nbr_bit, &i, info->si_pid))
	{
		while (i < 8)
			byte[i++] = 0;
	}
	if (sig == SIGUSR1)
		byte[nbr_bit] = '0';
	else
		byte[nbr_bit] = '1';
	if (++nbr_bit == 8)
	{
		c = ft_byte_to_char(byte);
		ft_putchar (c);
		nbr_bit = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	pid = getpid();
	ft_printf("PID : %d\n", pid);
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	while (1)
		pause();
	return (0);
}
