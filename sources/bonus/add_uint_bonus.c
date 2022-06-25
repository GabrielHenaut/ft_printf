/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_uint_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:21:17 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/06/24 22:41:44 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	handle_flags_uint(t_param *param)
{
	if (param->has_precision)
		fill_precision(param);
	if (param->width > param->str_len)
		if (fill_int_width(param) < 0)
			return (-1);
	return (param->str_len);
}

void	add_uint(unsigned int nbr, t_param *param)
{
	char	*str;
	char	*tmp;

	param->specifier = 'u';
	if (param->has_precision)
		param->zero = 0;
	tmp = param->str;
	str = ft_uitoa(nbr);
	param->str = ft_memjoin(tmp, param->str_len, str, ft_strlen(str) + 1);
	param->str_len += ft_strlen(param->str);
	free(tmp);
	free(str);
	if (handle_flags_uint(param) == -1)
		param->error = 1;
}
