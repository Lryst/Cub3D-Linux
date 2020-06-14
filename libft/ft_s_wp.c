/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_wp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 15:06:18 by lryst             #+#    #+#             */
/*   Updated: 2020/01/20 15:06:21 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_s_wp2(t_flags *prt, size_t *count, char *str)
{
	int i;

	i = -1;
	if (6 >= (prt->nbr_p))
	{
		while (++i < (prt->nbr_p))
			ft_putchar_c(str[i], count);
	}
	else if (6 < (prt->nbr_p))
	{
		if (6 < prt->nbr_f)
		{
			while (++i < (prt->nbr_f - 6))
				ft_putchar_c(' ', count);
		}
		ft_putstr_c(str, count);
	}
}

void	ft_s_wp3(t_flags *prt, size_t *count, int len, char *str)
{
	int i;

	i = -1;
	if (len >= (prt->nbr_p))
	{
		if (len <= prt->nbr_f)
		{
			while (++i < (prt->nbr_f - len))
				ft_putchar_c(' ', count);
		}
		i = -1;
		while (++i < (prt->nbr_p))
			ft_putchar_c(str[i], count);
	}
	else if (len < (prt->nbr_p))
	{
		if (len <= prt->nbr_f)
		{
			while (++i < (prt->nbr_f - len))
				ft_putchar_c(' ', count);
		}
		ft_putstr_c(str, count);
	}
}

void	ft_s_wp(t_flags *prt, va_list args, size_t *count)
{
	char	*str;
	int		len;
	char	*null;

	len = 0;
	str = va_arg(args, char *);
	null = "(null)";
	if (str == NULL)
		ft_s_wp2(prt, count, null);
	else
	{
		len = ft_strlen(str);
		ft_s_wp3(prt, count, len, str);
	}
}
