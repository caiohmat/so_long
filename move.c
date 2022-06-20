/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:23:50 by chideyuk          #+#    #+#             */
/*   Updated: 2021/11/25 20:44:20 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_moveempty(t_main *main, t_tile *tile)
{
	tile->type = PLAYER;
	main->playerdata.tile->type = EMPTY;
	main->playerdata.tile = tile;
}

void	ft_movecollect(t_main *main, t_tile *tile)
{
	tile->type = PLAYER;
	main->collect--;
	main->playerdata.tile->type = EMPTY;
	main->playerdata.tile = tile;
}

void	ft_moveexit(t_main *main, t_tile *tile)
{
	tile->type = PLAYER;
	main->playerdata.tile->type = EMPTY;
	main->playerdata.tile = NULL;
	main->moves++;
	printf("Moves: %d.\n", main->moves);
	printf("You cleared the game with %d moves.\n", main->moves);
	ft_end(main);
}
