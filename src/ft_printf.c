/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad < kfouad@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 11:48:45 by kfouad            #+#    #+#             */
/*   Updated: 2023/02/04 20:03:36 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

int	check_printf(char s, va_list arg)
{
	int		count;

	count = 0;
	if (s == 'c')
		count = ft_putchar(va_arg(arg, int));
	else if (s == 's')
		count = ft_putstr(va_arg(arg, char *));
	else if (s == 'd')
		count = ft_putnbr(va_arg(arg, int));
	else
		count += ft_putchar(s);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	arg;
	int		i;
	int		count;

	va_start(arg, s);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != '%')
			count += ft_putchar(s[i]);
		else
			count += check_printf(s[++i], arg);
		i++;
	}
	va_end(arg);
	return (count);
}
