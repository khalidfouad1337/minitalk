/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad <kfouad@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 19:36:37 by kfouad            #+#    #+#             */
/*   Updated: 2023/03/13 17:36:21 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_count;

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	send_sig(int count, int c, int pid)
{
	usleep(100);
	while (count < 8)
	{
		usleep(80);
		if (c % 2 == 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(80);
		c = c / 2;
		count++;
	}
}

void	c_handler(int sig)
{
	if (sig == SIGUSR1)
		g_count++;
}

int	main(int argc, char *argv[])
{
	int			pid;
	int			i;
	static int	count;
	static int	c;

	i = 0;
	count = 0;
	if (argc != 3)
		return (ft_printf("number of arg not valids!"));
	pid = ft_atoi(argv[1]);
	signal(SIGUSR1, c_handler);
	while (argv[2][i])
	{
		c = (unsigned char)argv[2][i];
		count = 0;
		send_sig(count, c, pid);
		i++;
	}
	if (g_count == ft_strlen(argv[2]) * 8)
		ft_printf("Message Sent Successfuly\n");
	else
		ft_printf("Message Didn't Sent Seccussfly\n");
	return (0);
}
