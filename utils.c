/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:24:06 by chideyuk          #+#    #+#             */
/*   Updated: 2021/11/25 16:36:44 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_ptrlen(char **s)
{
	int	counter;

	counter = 0;
	while (s[counter])
		counter++;
	return (counter);
}

void	ft_freemaptr(char **map)
{
	int	counter;

	counter = 0;
	while (map[counter])
	{
		free(map[counter]);
		counter++;
	}
	free(map);
}

static void	ft_bzero(void *b, size_t len)
{
	size_t	counter;
	char	*ptr;

	if (len == 0)
		return ;
	ptr = b;
	counter = 0;
	while (counter < len)
	{
		ptr[counter] = 0;
		counter++;
	}
}

void	*ft_calloc(size_t number, size_t size)
{
	void	*ptr;

	ptr = malloc(number * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, number * size);
	return (ptr);
}
