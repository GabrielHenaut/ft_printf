/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 17:57:04 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/06/24 06:46:42 by Ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	add_xnbr(unsigned int nbr, t_rtn_str *rtn)
{
	add_nbr_base(nbr, "0123456789abcdef", rtn);
}

void	add_xnbr_up(unsigned int nbr, t_rtn_str *rtn)
{
	add_nbr_base(nbr, "0123456789ABCDEF", rtn);
}

void	add_unbr(unsigned int nbr, t_rtn_str *rtn)
{
	add_nbr_base(nbr, "0123456789", rtn);
}

void	add_nbr(int nbr, t_rtn_str *rtn)
{
	if (nbr < 0)
	{
		append_to_str(rtn, '-');
		nbr *= -1;
	}
	add_unbr((unsigned int)nbr, rtn);
}
