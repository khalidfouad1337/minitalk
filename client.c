/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad < kfouad@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 20:55:32 by kfouad            #+#    #+#             */
/*   Updated: 2023/02/04 20:20:00 by kfouad           ###   ########.fr       */
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
		return (ft_printf("usage: ./client [valid server pid] [message]"));
	pid = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		c = argv[2][i];
		count = 0;
		while (count <= 8)
		{
			if (c % 2 == 1)
				kill(pid, SIGUSR2);
			if (c % 2 == 0)
				kill(pid, SIGUSR1);
			count++;
			c = c / 2;
		}
		i++;
	}
	return (0);
}
