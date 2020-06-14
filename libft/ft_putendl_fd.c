/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:06:49 by lryst             #+#    #+#             */
/*   Updated: 2020/06/14 00:41:28 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *p, int fd)
{
	if (p == NULL || fd < 0)
		return ;
	ft_putstr_fd(p, fd);
	ft_putchar_fd('\n', fd);
}
