/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad < kfouad@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:55:32 by kfouad            #+#    #+#             */
/*   Updated: 2023/02/07 20:10:13 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_sig(int count, int c, int pid)
{
	while (count < 8)
	{
		if (c % 2 == 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
		c = c / 2;
		count++;
	}
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
	{
		ft_printf("number of arg not valids!");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		c = argv[2][i];
		count = 0;
		send_sig(count, c, pid);
		i++;
	}
	return (0);
}
