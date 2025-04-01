/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashobajo <ashobajo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 18:22:00 by ashobajo          #+#    #+#             */
/*   Updated: 2024/09/21 19:04:17 by ashobajo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	file_parse(t_base *base, char **file, char buf[], int fd)
{
	char			*tmp;

	tmp = ft_strjoin(*file, buf);
	free(*file);
	*file = tmp;
	if (*file == 0)
	{
		close(fd);
		base_destroy(base, "map_init(): ft_strjoin()", errno);
	}
}

static void	file_read(t_base *base, char **file, char buf[], int fd)
{
	int				ret;

	ret = 1;
	while (ret != 0)
	{
		ret = read(fd, buf, 1024);
		if (ret == -1)
		{
			free(*file);
			close(fd);
			base_destroy(base, "map_init(): read()", errno);
		}
		else
		{
			buf[ret] = 0;
			file_parse(base, file, buf, fd);
		}
	}
}

static char	*file_init(t_base *base, int fd)
{
	char			*file;

	file = ft_calloc(1, 1);
	if (file == 0)
	{
		close(fd);
		base_destroy(base, "map_init(): ft_calloc()", errno);
	}
	return (file);
}

void	map_init(t_base *base, char *filename)
{
	int				fd;
	char			*file;
	char			buf[1024 + 1];

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		base_destroy(base, filename, errno);
	file = file_init(base, fd);
	file_read(base, &file, buf, fd);
	close(fd);
	read_map(base, file);
	free(file);
}
