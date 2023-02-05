/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfouad < kfouad@student.1337.ma>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 19:05:54 by kfouad            #+#    #+#             */
/*   Updated: 2023/02/05 13:44:27 by kfouad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

unsigned char	ft_byte_to_char(char *byte);
void	handler(int sig, siginfo_t *info, void *p);
int		ft_atoi(char *str);
int		check_printf(char s, va_list arg);
int		ft_printf(const char *s, ...);
int		ft_putchar(char c);
int		ft_putnbr(int nb);
int		ft_putptr(unsigned long ptr);
int		ft_putstr(char *str);

#endif
