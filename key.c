/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:23:37 by chideyuk          #+#    #+#             */
/*   Updated: 2021/11/25 20:44:37 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_move(t_main *main, t_tile *tile)
{
	if (tile->type == EMPTY)
	{
		ft_moveempty(main, tile);
		main->moves++;
		printf("Moves: %d.\n", main->moves);
	}
	else if (tile->type == COLLECTABLE)
	{
		ft_movecollect(main, tile);
		main->moves++;
		printf("Moves: %d.\n", main->moves);
	}
	else if (tile->type == EXIT && main->collect == 0)
		ft_moveexit(main, tile);
	else
		return ;
}

int	ft_key(int key, t_main *main)
{
	if (key == 65307)
	{
		ft_end(main);
		return (1);
	}
	else if (key == 119)
		ft_move(main, main->playerdata.tile->up);
	else if (key == 97)
		ft_move(main, main->playerdata.tile->left);
	else if (key == 115)
		ft_move(main, main->playerdata.tile->down);
	else if (key == 100)
		ft_move(main, main->playerdata.tile->right);
	else
		return (0);
	return (1);
}
