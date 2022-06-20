/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:23:43 by chideyuk          #+#    #+#             */
/*   Updated: 2021/11/25 17:12:19 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen(const char *s);

int	ft_bercheck(int argc, char *filename)
{
	int		counter;
	char	*ber;

	ber = ".ber";
	if (argc < 2)
		return (ft_error("No file name provided"));
	counter = ft_strlen(filename) - 4;
	if (counter <= 0)
		return (ft_error("Provided file is not a .ber file"));
	while (filename[counter])
	{
		if (filename[counter] != *ber)
			return (ft_error("Provided file is not a .ber file"));
		counter++;
		ber++;
	}
	return (1);
}

static t_map	ft_getmapdata(char **map)
{
	t_map	mapdata;

	mapdata.size.x = ft_strlen(map[0]);
	mapdata.size.y = ft_ptrlen(map);
	mapdata.check.x = 0;
	mapdata.check.y = 0;
	mapdata.player = 0;
	mapdata.keys = 0;
	mapdata.door = 0;
	return (mapdata);
}

static int	ft_tests(char **map, t_map *mapdata)
{
	int	x;
	int	y;

	x = mapdata->check.x;
	y = mapdata->check.y;
	if (map[y][x] != 'P' && map[y][x] != 'E' && map[y][x] != 'C'
		&& map[y][x] != '0' && map[y][x] != '1')
		return (ft_error("only the characters 01CEP are allowed"));
	else if (map[y][x] == 'P')
		mapdata->player++;
	else if (map[y][x] == 'E')
		mapdata->door++;
	else if (map[y][x] == 'C')
		mapdata->keys++;
	if ((y == 0 || y == mapdata->size.y - 1 || x == 0
			|| x == mapdata->size.x - 1) && map[y][x] != '1')
		return (ft_error("map should be surrounded by walls"));
	return (1);
}

int	ft_mapcheck(char **map)
{
	t_map	mapdata;

	mapdata = ft_getmapdata(map);
	while (map[mapdata.check.y])
	{
		if (ft_strlen(map[mapdata.check.y]) != (size_t)mapdata.size.x)
			return (ft_error("Map provided is not a rectangle"));
		while (map[mapdata.check.y][mapdata.check.x])
		{
			if (ft_tests(map, &mapdata) == 0)
				return (0);
			mapdata.check.x++;
		}
		mapdata.check.x = 0;
		mapdata.check.y++;
	}
	if (mapdata.player < 1 || mapdata.keys < 1 || mapdata.door < 1)
		return (ft_error("There should be at least one P, C and E"));
	if (mapdata.player > 1)
		return (ft_error("only single player allowed"));
	return (1);
}
