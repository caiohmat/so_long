/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:23:56 by chideyuk          #+#    #+#             */
/*   Updated: 2021/11/25 22:05:40 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_tile	**ft_startmap(int argc, char **argv, t_main *main)
{
	char	**map;
	t_tile	**tilemap;

	if (ft_bercheck(argc, argv[1]) == 0)
		return (NULL);
	map = ft_getmap(argv[1]);
	if (map == NULL)
		return (NULL);
	if (ft_mapcheck(map) == 0)
	{
		ft_freemaptr(map);
		return (NULL);
	}
	tilemap = ft_createtile(map, main);
	ft_freemaptr(map);
	if (!tilemap)
		return (NULL);
	return (tilemap);
}

static void	ft_startgame(t_main *main)
{
	main->mlx = mlx_init();
	main->window = mlx_new_window(main->mlx, main->winsize.x,
			main->winsize.y, "so_long");
	mlx_hook(main->window, 17, 0, ft_end, main);
	ft_openimg(main);
}

int	ft_startup(t_main *main, int argc, char **argv)
{
	main->collect = 0;
	main->moves = 0;
	main->tilemap = ft_startmap(argc, argv, main);
	if (main->tilemap == NULL)
		return (0);
	ft_startgame(main);
	return (1);
}
