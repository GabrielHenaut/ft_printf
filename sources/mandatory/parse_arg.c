/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 00:52:35 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/06/24 06:46:13 by Ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	handle_conversions(char c, va_list args, t_rtn_str *rtn)
{
	if (c == 's')
		add_str(rtn, va_arg(args, char *));
	else if (c == 'c')
		append_to_str(rtn, va_arg(args, int));
	else if (c == 'd' || c == 'i')
		add_nbr(va_arg(args, int), rtn);
	else if (c == 'u')
		add_unbr(va_arg(args, unsigned int), rtn);
	else if (c == 'x')
		add_xnbr(va_arg(args, unsigned int), rtn);
	else if (c == 'X')
		add_xnbr_up(va_arg(args, unsigned int), rtn);
	else if (c == 'p')
		add_addr(va_arg(args, void *), rtn);
	else if (c == '%')
		append_to_str(rtn, '%');
}

void	parse_arg(char c, va_list args, t_rtn_str *rtn)
{
	if (ft_strchr("csdiuxXp%", c))
		handle_conversions(c, args, rtn);
	else
		append_to_str(rtn, '%');
}
