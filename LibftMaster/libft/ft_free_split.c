/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgonza <davgonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:58:41 by marias-e          #+#    #+#             */
/*   Updated: 2023/03/30 17:59:05 by davgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_split(char ***array)
{
	int	i;

	if (*array)
	{
		i = 0;
		while ((*array)[i])
		{
			free((*array)[i]);
			i++;
		}
		free(*array);
		*array = 0;
	}
}
