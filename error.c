/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chideyuk <chideyuk@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:23:26 by chideyuk          #+#    #+#             */
/*   Updated: 2021/11/24 20:29:40 by chideyuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_error(char *message)
{
	printf("Error\n%s\n", message);
	return (0);
}

void	*ft_nullerror(char *message)
{
	printf("Error\n%s\n", message);
	return (NULL);
}
