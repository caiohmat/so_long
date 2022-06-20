/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:23:53 by chideyuk          #+#    #+#             */
/*   Updated: 2021/11/25 22:05:23 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct xy
{
	int	x;
	int	y;
}		t_xy;

typedef enum tiletype
{
	EMPTY = '0',
	WALL = '1',
	COLLECTABLE = 'C',
	EXIT = 'E',
	PLAYER = 'P'
}			t_tiletype;

typedef struct tile
{
	t_tiletype	type;
	t_xy		tilepos;
	struct tile	*up;
	struct tile	*down;
	struct tile	*left;
	struct tile	*right;
}			t_tile;

typedef struct map
{
	t_xy	size;
	t_xy	check;
	int		player;
	int		keys;
	int		door;
}		t_map;

typedef struct player
{
	t_tile	*tile;
	void	*playerimg;
}		t_player;

typedef struct main
{
	void		*mlx;
	void		*window;
	t_xy		winsize;
	t_xy		imgsize;
	t_player	playerdata;
	t_tile		**tilemap;
	int			collect;
	int			moves;
	void		*wallimg;
	void		*collectimg;
	void		*exitimg;
}			t_main;

int		ft_startup(t_main *main, int argc, char **argv);
int		ft_bercheck(int argc, char *filename);
int		ft_ptrlen(char	**s);
char	**ft_getmap(char *mapfile);
int		ft_error(char *message);
void	*ft_nullerror(char *message);
int		ft_mapcheck(char **map);
void	ft_freemaptr(char	**map);
t_tile	**ft_createtile(char **map, t_main	*main);
int		ft_end(t_main	*main);
void	ft_openimg(t_main	*main);
int		ft_key(int key, t_main *main);
void	ft_moveexit(t_main *main, t_tile *tile);
void	ft_movecollect(t_main *main, t_tile *tile);
void	ft_moveempty(t_main *main, t_tile *tile);
int		ft_update(t_main *main);
void	*ft_calloc(size_t	number, size_t	size);

#endif