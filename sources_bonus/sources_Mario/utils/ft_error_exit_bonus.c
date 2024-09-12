/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_exit_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgonza <davgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:33:42 by marias-e          #+#    #+#             */
/*   Updated: 2023/06/21 12:23:33 by davgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mario_bonus.h"

void	ft_error_exit(char *error_str, int error_code)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd(error_str, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	exit(error_code);
}
