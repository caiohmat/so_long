/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:24:03 by chideyuk          #+#    #+#             */
/*   Updated: 2021/11/24 20:38:57 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_putimage(t_tile tile, t_main *main, t_xy tilepos)
{
	if (tile.type == WALL)
		mlx_put_image_to_window(main->mlx, main->window,
			main->wallimg, tilepos.x, tilepos.y);
	else if (tile.type == COLLECTABLE)
		mlx_put_image_to_window(main->mlx, main->window,
			main->collectimg, tilepos.x, tilepos.y);
	else if (tile.type == EXIT)
		mlx_put_image_to_window(main->mlx, main->window,
			main->exitimg, tilepos.x, tilepos.y);
	else if (tile.type == PLAYER)
		mlx_put_image_to_window(main->mlx, main->window,
			main->playerdata.playerimg, tilepos.x, tilepos.y);
}

int	ft_update(t_main *main)
{
	t_tile	tile;
	int		y;
	int		x;

	mlx_clear_window(main->mlx, main->window);
	y = 0;
	while (main->tilemap[y] != NULL)
	{
		x = 0;
		while (main->tilemap[y][x].type != 0)
		{
			tile = main->tilemap[y][x];
			ft_putimage(tile, main, tile.tilepos);
			x++;
		}
		y++;
	}
	return (1);
}
