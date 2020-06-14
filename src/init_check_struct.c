/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_check_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 10:05:33 by lryst             #+#    #+#             */
/*   Updated: 2020/06/14 01:09:58 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_check_struct(t_check_struct *ret)
{
	ret->width = -1;
	ret->height = -1;
	ret->no = -1;
	ret->so = -1;
	ret->we = -1;
	ret->ea = -1;
	ret->s = -1;
	ret->f = -1;
	ret->c = -1;
	ret->map = -1;
	ret->position = 0;
}

void	init_cub3d(t_cub3d *cub)
{
	ft_bzero(cub, sizeof(t_cub3d));
	ft_bzero(&cub->closed_map, sizeof(char **));
	ft_bzero(&cub->no, sizeof(t_texture));
	ft_bzero(&cub->move, sizeof(t_move));
	ft_bzero(&cub->map, sizeof(t_map));
	ft_bzero(&cub->player, sizeof(t_player));
	cub->tmp = ft_newstring(0);
}

int		check_struct(t_check_struct *ret)
{
	if (ret->width == 1 && ret->height == 1 && ret->no == 1 &&
	ret->so == 1 && ret->we == 1 && ret->ea == 1 && ret->s == 1
	&& ret->f == 1 && ret->c == 1)
	{
		return (1);
	}
	return (0);
}
