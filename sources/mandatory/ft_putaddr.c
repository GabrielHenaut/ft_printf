/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:26:57 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/06/24 06:43:23 by Ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	add_addr(void *nbr, t_rtn_str *rtn)
{
	if (!nbr)
		add_str(rtn, "(nil)");
	else
	{
		add_str(rtn, "0x");
		add_nbr_base((uint64_t) nbr, "0123456789abcdef", rtn);
	}
}
