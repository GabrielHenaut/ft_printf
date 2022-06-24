/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_pointer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:19:15 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/06/24 06:50:18 by Ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static char	*int_to_pointer(size_t nbr)
{
	char	*hex;
	char	*address;

	if (nbr == 0)
	{
		address = ft_strdup("(nil)");
	}
	else
	{
		hex = ft_uitox(nbr);
		address = ft_strjoin("0x", hex);
		free(hex);
	}
	return (address);
}

static int	handle_flags_pointer(t_param *param)
{
	if (param->str_len < param->width)
		if (fill_width(param) < 0)
			return (-1);
	return (param->str_len);
}

void	add_pointer(void *nbr, t_param *param)
{
	char	*str;
	char	*tmp;

	param->specifier = 'p';
	tmp = param->str;
	str = int_to_pointer((size_t) nbr);
	param->str = ft_memjoin(tmp, param->str_len, str, ft_strlen(str) + 1);
	param->str_len += ft_strlen(param->str);
	free(tmp);
	free(str);
	if (handle_flags_pointer(param) == -1)
		param->error = 1;
}
