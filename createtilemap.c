/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createtilemap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:23:16 by chideyuk          #+#    #+#             */
/*   Updated: 2021/11/25 22:31:19 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen(const char	*s);

static t_tile	**ft_tilealloc(char	**map)
{
	t_tile	**tilemap;
	int		counter;

	tilemap = ft_calloc((ft_ptrlen(map) + 1), sizeof(t_tile *));
	if (tilemap == NULL)
		return (NULL);
	counter = 0;
	while (map[counter] != NULL)
	{
		tilemap[counter] = ft_calloc((ft_strlen(*map) + 1), sizeof(t_tile));
		if (tilemap[counter] == NULL)
		{
			while (counter > 0)
			{
				counter--;
				free(tilemap[counter]);
			}
			free(tilemap);
			return (NULL);
		}
		counter++;
	}
	return (tilemap);
}

static void	ft_tileset(t_tile **tilemap, int y, int x)
{
	tilemap[y][x].tilepos.y = y * 64;
	tilemap[y][x].tilepos.x = x * 64;
	if (y != 0)
		tilemap[y][x].up = &tilemap[y - 1][x];
	if (tilemap[y + 1] != NULL)
		tilemap[y][x].down = &tilemap[y + 1][x];
	if (x != 0)
		tilemap[y][x].left = &tilemap[y][x - 1];
	tilemap[y][x].right = &tilemap[y][x + 1];
}

static void	ft_varset(t_tile	*tile, t_main *main)
{
	if (tile->type == PLAYER)
		main->playerdata.tile = tile;
	else if (tile->type == COLLECTABLE)
		main->collect++;
}

static t_tiletype	ft_tiletype(char type)
{
	if (type == '0')
		return (EMPTY);
	else if (type == '1')
		return (WALL);
	else if (type == 'C')
		return (COLLECTABLE);
	else if (type == 'E')
		return (EXIT);
	else
		return (PLAYER);
}

t_tile	**ft_createtile(char **map, t_main	*main)
{
	t_tile	**tilemap;
	int		x;
	int		y;

	tilemap = ft_tilealloc(map);
	if (!tilemap)
		return (ft_nullerror("Failed memory allocation for tilemap"));
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			tilemap[y][x].type = ft_tiletype(map[y][x]);
			ft_tileset(tilemap, y, x);
			ft_varset(&tilemap[y][x], main);
			x++;
		}
		tilemap[y][x].type = 0;
		y++;
	}
	tilemap[y] = NULL;
	main->winsize.x = x * 64;
	main->winsize.y = y * 64;
	return (tilemap);
}
