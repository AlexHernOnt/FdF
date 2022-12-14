/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <ahernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 16:40:10 by ahernand          #+#    #+#             */
/*   Updated: 2022/11/09 11:56:31 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free(char **str)
{
	if (*str != NULL && str != NULL)
	{
		free(*str);
		*str = NULL;
	}
}

int	ft_save_line(char **saved, char **line, int fd)
{
	int		i;
	char	*aux;

	i = 0;
	while (saved[fd][i] != '\n')
		i++;
	*line = ft_substr(saved[fd], 0, i);
	aux = ft_strdup(&saved[fd][i + 1]);
	free(saved[fd]);
	saved[fd] = aux;
	return (1);
}

int	ft_ret(char **saved, char **line, int fd, int n_read)
{
	if (n_read < 0)
		return (-1);
	else if (ft_strchr(saved[fd], '\n'))
		return (ft_save_line(saved, line, fd));
	else if (n_read == 0 && (saved[fd] == NULL || saved[fd][0] == '\0'))
	{
		*line = ft_strdup("");
		ft_free(&saved[fd]);
		return (0);
	}
	else
	{
		*line = ft_strdup(saved[fd]);
		ft_free(&saved[fd]);
		return (0);
	}
}

int	get_next_line(int fd, char **line, int n_read)
{
	static char	*saved[4096];
	char		*tmp;
	char		*aux;

	tmp = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (fd < 0 || !line || BUFFER_SIZE < 1 || !(tmp))
		return (-1);
	n_read = read(fd, tmp, BUFFER_SIZE);
	while (n_read > 0)
	{
		tmp[n_read] = '\0';
		if (saved[fd] == NULL)
			saved[fd] = ft_strdup(tmp);
		else
		{
			aux = ft_strjoin(saved[fd], tmp);
			free(saved[fd]);
			saved[fd] = aux;
		}
		if (ft_strchr(saved[fd], '\n'))
			break ;
		n_read = read(fd, tmp, BUFFER_SIZE);
	}
	free(tmp);
	return (ft_ret(saved, line, fd, n_read));
}
