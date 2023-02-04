/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad < kfouad@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:37:42 by kfouad            #+#    #+#             */
/*   Updated: 2023/02/04 20:05:20 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	ft_putnbr(int nb)
{
	long	n;
	int		count;

	count = 0;
	n = nb;
	if (n < 0)
	{
		count += ft_putchar('-');
		n = n * -1;
	}
	if (n >= 10)
	{
		count += ft_putnbr(n / 10);
		count += ft_putnbr(n % 10);
	}
	else
		count += ft_putchar(n + 48);
	return (count);
}
