/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:42:01 by lryst             #+#    #+#             */
/*   Updated: 2020/01/20 14:44:57 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_s_l_space(t_flags *prt, char q, va_list args, size_t *count)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	str = va_arg(args, char*);
	if (str == NULL)
	{
		while (i++ < ((prt->nbr_f) - 6))
			ft_putchar_c(q, count);
		ft_putstr_c("(null)", count);
	}
	if (str != NULL)
	{
		len = ft_strlen(str);
		while (i++ < ((prt->nbr_f) - len))
			ft_putchar_c(q, count);
		ft_putstr_c(str, count);
	}
}

void	ft_s_right(t_flags *prt, va_list args, size_t *count)
{
	int		i;
	char	*str;

	str = va_arg(args, char*);
	if (str != NULL)
	{
		i = ft_strlen(str);
		ft_putstr_c(str, count);
		while (i++ < (prt->nbr_f))
			ft_putchar_c(' ', count);
	}
	else
	{
		i = 6;
		ft_putstr_c("(null)", count);
		while (i++ < (prt->nbr_f))
			ft_putchar_c(' ', count);
	}
}

void	ft_s_lz(t_flags *prt, va_list args, size_t *count)
{
	int		u;
	char	*s;
	int		c;

	u = 0;
	s = va_arg(args, char*);
	c = ft_strlen(s);
	if (c > (prt->nbr_f))
	{
		while (u++ < (prt->nbr_f))
			ft_putchar_c(s[u], count);
	}
	else if (c < (prt->nbr_f))
		ft_putstr_c(s, count);
}
