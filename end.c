/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:23:23 by chideyuk          #+#    #+#             */
/*   Updated: 2021/11/24 20:29:28 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_freetile(t_main	*main)
{
	t_tile	**tilemap;

	tilemap = main->tilemap;
	while (*main->tilemap != NULL)
	{
		free(*main->tilemap);
		main->tilemap++;
	}
	free(tilemap);
}

int	ft_end(t_main	*main)
{
	ft_freetile(main);
	mlx_destroy_window(main->mlx, main->window);
	mlx_destroy_image(main->mlx, main->wallimg);
	mlx_destroy_image(main->mlx, main->collectimg);
	mlx_destroy_image(main->mlx, main->exitimg);
	mlx_destroy_image(main->mlx, main->playerdata.playerimg);
	mlx_destroy_display(main->mlx);
	free(main->mlx);
	exit(0);
}
