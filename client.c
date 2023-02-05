/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad < kfouad@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:55:32 by kfouad            #+#    #+#             */
/*   Updated: 2023/02/05 15:44:11 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char *argv[])
{
	int	pid;
	int	i;
	int	count;
	int	c;

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
		while (count < 8)
		{
			if (c % 2 == 1)
				kill(pid, SIGUSR2);
			if (c % 2 == 0)
				kill(pid, SIGUSR1);
			usleep(100);
			c = c / 2;
			count++;
		}
		i++;
	}
	return (0);
}
