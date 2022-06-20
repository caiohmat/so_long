/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:23:40 by chideyuk          #+#    #+#             */
/*   Updated: 2021/11/24 20:32:52 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_main	main;

	if (ft_startup(&main, argc, argv) == 0)
		return (0);
	mlx_key_hook(main.window, ft_key, &main);
	mlx_loop_hook(main.mlx, ft_update, (void *)&main);
	mlx_loop(main.mlx);
	return (0);
}
