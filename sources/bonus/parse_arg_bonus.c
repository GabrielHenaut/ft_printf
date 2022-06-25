/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 00:52:35 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/06/25 05:19:28 by Ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	init_param(t_param *param)
{
	param->precision = 0;
	param->width = 0;
	param->str = NULL;
	param->str_len = 0;
	param->minus = 0;
	param->zero = 0;
	param->hash = 0;
	param->space = 0;
	param->plus = 0;
	param->has_precision = 0;
	param->error = 0;
}

static void	ft_parse_precision(char *str, va_list args, t_param *param)
{
	int	specified;

	specified = 0;
	param->has_precision = 1;
	while (!ft_strchr(CONVERSIONS, *str))
	{
		if ((ft_isdigit(*str) || *str == '*') && !specified)
		{
			if (*str == '*')
				param->precision = va_arg(args, int);
			else
				param->precision = ft_atoi(str);
			specified = 1;
		}
		str++;
	}
	if (specified == 0)
		param->precision = 0;
}

static int	handle_width(char *str, va_list args, t_param *param, int i)
{
	if (str[i] == '*')
		param->width = va_arg(args, int);
	else
		param->width = ft_atoi(&str[i]);
	if ((int)param->width < 0)
	{
		param->minus = 1;
		param->width *= -1;
	}
	return (1);
}

static int	parse_flags(char *str, va_list args, t_param *param)
{
	int	entered;
	int	i;

	i = 0;
	entered = 0;
	while (str[i] != '.' && !ft_strchr(CONVERSIONS, str[i]))
	{
		if (str[i] == '-')
			param->minus = 1;
		if (str[i] == '+')
			param->plus = 1;
		if (str[i] == ' ')
			param->space = 1;
		if (str[i] == '#')
			param->hash = 1;
		if (str[i] == '0' && !ft_isdigit(str[i - 1]))
			param->zero = 1;
		else if (((str[i] > '0' && str[i] <= '9') || str[i] == '*') && !entered)
			entered = handle_width(str, args, param, i);
		i++;
	}
	return (i);
}

void	parse_arg(char *str, va_list args, t_rtn_str *rtn)
{
	t_param	param;
	char	*tmp;

	init_param(&param);
	str += parse_flags(str, args, &param);
	if (*str == '.')
	{
		param.precision = 1;
		ft_parse_precision(str++, args, &param);
		while (!ft_strchr(CONVERSIONS, *str))
			str++;
	}
	while (!ft_strchr(CONVERSIONS, *str))
			str++;
	handle_conversions(*str, args, &param);
	tmp = ft_memjoin(rtn->str, rtn->size, param.str, param.str_len);
	free(rtn->str);
	rtn->str = tmp;
	rtn->size += param.str_len;
	free(param.str);
}
