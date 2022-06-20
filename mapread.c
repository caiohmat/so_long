/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:23:47 by chideyuk          #+#    #+#             */
/*   Updated: 2021/11/26 19:31:05 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "so_long.h"
#include "gnlmod/get_next_line.h"

static int	ft_linecount(char	*mapfile)
{
	int		lines;
	int		fd;
	int		reads;
	char	c;

	fd = open(mapfile, O_RDONLY);
	if (!fd)
		return (0);
	lines = 1;
	reads = 1;
	while (reads > 0)
	{
		reads = read(fd, &c, 1);
		if (reads == 0)
			break ;
		if (reads < 0)
		{
			close(fd);
			return (0);
		}
		if (c == '\n')
			lines++;
	}
	close(fd);
	return (lines);
}

static char	**ft_mapalloc(int lines)
{
	char	**map;

	map = ft_calloc((lines + 1), sizeof(char *));
	if (map == NULL)
		return (ft_nullerror("could not allocate memory"));
	return (map);
}

char	**ft_getmap(char *mapfile)
{
	char	**map;
	int		fd;
	int		counter;
	int		lines;

	lines = ft_linecount(mapfile);
	if (lines <= 2)
		return (ft_nullerror("Could not read file or map has too few lines"));
	map = ft_mapalloc(lines);
	if (map == NULL)
		return (NULL);
	fd = open(mapfile, O_RDONLY);
	counter = 0;
	while (counter < lines)
	{
		map[counter] = get_next_linemod(fd);
		counter++;
	}
	map[counter] = NULL;
	close(fd);
	return (map);
}
