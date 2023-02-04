/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad < kfouad@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 17:29:15 by kfouad            #+#    #+#             */
/*   Updated: 2023/02/04 20:05:27 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	ft_putptr(unsigned long ptr)
{
	int	count;

	count = 0;
	count += ft_putstr("0x");
	count += ft_put_hex(ptr);
	return (count);
}
