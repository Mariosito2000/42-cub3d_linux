/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgonza <davgonza@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 10:17:51 by davgonza          #+#    #+#             */
/*   Updated: 2022/10/26 11:27:32 by davgonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_realloc(char **src, size_t size)
{
	char	*temp;
	int		n;

	if (!src)
		return (0);
	n = -1;
	temp = ft_strdup_ovs(0, size);
	if (!temp)
	{
		freed(src, 0);
		return (0);
	}
	if (src && *src)
	{
		while ((*src)[++n])
			temp[n] = (*src)[n];
		temp[n] = 0;
		freed (src, 0);
	}
	return (temp);
}

static int	ft_read_stash(char **dest, char **excess)
{
	int		n;
	char	*temp;

	*dest = 0;
	if (!(*excess))
		return (1);
	n = ft_strchr_pos(*excess, '\n', 0);
	if (n < 0)
		return (1);
	*dest = ft_substr_gnl(*excess, 0, n + 1);
	if ((*dest)[0] == 0)
	{
		freed(dest, excess);
		return (0);
	}
	if (ft_strchr_pos(*excess, 0, 1) > n)
	{
		temp = ft_strdup_ovs(*excess, 0);
		freed(excess, 0);
		*excess = ft_substr_gnl(temp, n + 1, ft_strlen_prot(&((temp)[n + 1])));
		freed(&temp, 0);
	}
	else if (*excess)
		freed(excess, 0);
	return (1);
}

static int	ft_read_fd(char **dest, char **excess, int fd)
{
	int	b_size;
	int	bytes;
	int	n;

	b_size = ft_strlen_prot(*excess);
	bytes = BUFFER_SIZE;
	while (bytes >= BUFFER_SIZE && ft_strchr_pos(*excess, '\n', 0) < 0)
	{
		b_size += BUFFER_SIZE;
		*excess = ft_realloc(&(*excess), b_size + 1);
		if (!*excess)
			return (0);
		bytes = read(fd, &((*excess)[b_size - BUFFER_SIZE]), BUFFER_SIZE);
		if (bytes < 0)
			return (freed(excess, 0));
	}
	n = ft_strchr_pos(*excess, '\n', 1) + 1;
	*dest = ft_substr_gnl(*excess, 0, n);
	if (*dest == 0 || **dest == 0)
		return (freed(excess, dest));
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*excess[1024];
	char		*buffer;
	char		*temp;
	int			n;

	if (fd < 0 || fd >= 1024)
		return (0);
	if (!ft_read_stash(&buffer, &(excess[fd])))
		return (0);
	if (!buffer)
	{
		if (!ft_read_fd(&buffer, &(excess[fd]), fd))
			return (0);
		n = ft_strchr_pos((excess[fd]), '\n', 1) + 1;
		if ((int)ft_strlen_prot((excess[fd])) > n)
		{
			temp = ft_strdup_ovs((excess[fd]), 0);
			freed(&(excess[fd]), 0);
			(excess[fd]) = ft_substr_gnl(temp, n, ft_strlen_prot(&((temp)[n])));
			freed(&temp, 0);
		}
		else if ((excess[fd]))
			freed(&(excess[fd]), 0);
	}
	return (buffer);
}
