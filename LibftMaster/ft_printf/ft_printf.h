/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgonza <davgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:56:22 by davgonza          #+#    #+#             */
/*   Updated: 2022/10/26 11:33:24 by davgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

int		ft_printf(char const *format, ...);
int		ft_putchar(char c);
int		ft_putnbr_base(int nbr, char *base);
int		ft_putstr(char *str);
int		ft_putunnbr(unsigned int nbr);
int		ft_putptr(void *ptr);
int		ft_putnbr(int nb);
void	ft_printnbr(char c);

#endif