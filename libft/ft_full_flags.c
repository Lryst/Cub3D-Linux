/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_full_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lryst <lryst@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:40:43 by lryst             #+#    #+#             */
/*   Updated: 2020/01/20 14:28:52 by lryst            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_just_flag(t_flags *prt, size_t *count, va_list args)
{
	if (prt->flags == 1)
		ft_flag_z(prt, count, args);
	if (prt->flags == 2)
		ft_flags_m(prt, count, args);
}

void	ft_full_flags_m(t_flags *prt, size_t *count, va_list args)
{
	unsigned long	u;

	u = 0;
	ft_precision(prt, &u, args);
	*count = *count + u;
	if (u < ((unsigned int)prt->nbr_f))
	{
		while (u++ < (unsigned int)prt->nbr_f)
			ft_putchar_c(' ', count);
	}
}

void	ft_full_flags(t_flags *prt, size_t *count, va_list args)
{
	if (prt->flags == 2)
		ft_full_flags_m(prt, count, args);
	if (prt->flags == 1)
	{
		if (prt->nbr_f > prt->nbr_p)
		{
			(prt->conv == 1 || prt->conv == 2) ?
			ft_di_width_p(prt, args, count) : 0;
			prt->conv == 3 ? ft_u_width_p(prt, args, count) : 0;
			prt->conv == 4 ? ft_x_width_p(prt, args, count) : 0;
			prt->conv == 5 ? ft_maj_x_width_p(prt, args, count) : 0;
			prt->conv == 7 ? ft_s_w_p(prt, args, count) : 0;
		}
		else if (prt->nbr_f <= prt->nbr_p)
			ft_precision(prt, count, args);
	}
}
