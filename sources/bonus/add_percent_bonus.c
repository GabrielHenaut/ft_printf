/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_percent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 20:52:46 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/06/24 06:54:36 by Ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	add_percent(t_param *param)
{
	char	*str;
	char	*tmp;

	param->specifier = '%';
	tmp = param->str;
	str = ft_strdup("%");
	param->str = ft_memjoin(tmp, param->str_len, str, ft_strlen(str) + 1);
	param->str_len += ft_strlen(param->str);
	free(tmp);
	free(str);
}
