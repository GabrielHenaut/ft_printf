/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:27:53 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/06/24 06:53:58 by Ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	handle_flags_int(t_param *param)
{
	char	*tmp;

	if (param->has_precision)
		if (fill_precision_int(param) < 0)
			return (-1);
	tmp = param->str;
	if (param->plus && tmp[0] != '-')
		param->str = ft_strjoin("+", tmp);
	else if (param->space && tmp[0] != '-')
		param->str = ft_strjoin(" ", tmp);
	param->str_len++;
	if (param->width > param->str_len)
		if (fill_int_width(param) < 0)
			return (-1);
	if ((param->plus && tmp[0] != '-') || (param->space && tmp[0] != '-'))
	{
		param->str_len++;
		free(tmp);
	}
	return (param->str_len);
}

void	add_int(int nbr, t_param *param)
{
	char	*tmp;
	char	*str;

	param->specifier = 'i';
	if (param->has_precision)
		param->zero = 0;
	tmp = param->str;
	str = ft_itoa(nbr);
	param->str = ft_memjoin(tmp, param->str_len, str, ft_strlen(str) + 1);
	param->str_len += ft_strlen(param->str) - 1;
	free(tmp);
	free(str);
	if (handle_flags_int(param) == -1)
		param->error = 1;
}
