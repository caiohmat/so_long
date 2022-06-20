/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:23:34 by chideyuk          #+#    #+#             */
/*   Updated: 2021/11/24 20:31:52 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_openimg(t_main	*main)
{
	main->imgsize.x = 64;
	main->imgsize.y = 64;
	main->wallimg = mlx_xpm_file_to_image(main->mlx,
			"image/wall.xpm", &main->imgsize.x, &main->imgsize.y);
	main->playerdata.playerimg = mlx_xpm_file_to_image(main->mlx,
			"image/player.xpm", &main->imgsize.x, &main->imgsize.y);
	main->collectimg = mlx_xpm_file_to_image(main->mlx,
			"image/key.xpm", &main->imgsize.x, &main->imgsize.y);
	main->exitimg = mlx_xpm_file_to_image(main->mlx,
			"image/door.xpm", &main->imgsize.x, &main->imgsize.y);
}
