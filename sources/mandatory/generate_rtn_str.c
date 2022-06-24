/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_rtn_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 22:42:33 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/06/24 06:45:44 by Ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	generate_rtn_str(const char *fmt, va_list args, t_rtn_str *rtn)
{
	int	i;

	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			i++;
			parse_arg(fmt[i], args, rtn);
		}
		else
			append_to_str(rtn, fmt[i]);
		i++;
	}
}
