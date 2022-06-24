/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append_to_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 23:40:50 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/06/24 06:44:48 by Ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_strjoin_free(char *s1, char *s2, t_rtn_str *rtn)
{
	char	*str;
	int		len;

	len = rtn->size;
	str = (char *)ft_memjoin(s1, len, s2, 2);
	str[len + 1] = '\0';
	free(s1);
	return (str);
}

static char	*ft_strnew(int size)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	str[size] = '\0';
	return (str);
}

static char	*ft_strnew_char(char c, int size)
{
	char	*str;

	str = ft_strnew(size);
	while (size--)
		str[size] = c;
	return (str);
}

void	append_to_str(t_rtn_str *rtn, char c)
{
	char	*tmp;

	tmp = ft_strnew_char(c, 1);
	rtn->str = ft_strjoin_free(rtn->str, tmp, rtn);
	rtn->size++;
	free(tmp);
}

void	add_str(t_rtn_str *rtn, char *str)
{
	if (!str)
		add_str(rtn, "(null)");
	else
	{
		while (*str)
		{
			append_to_str(rtn, *str);
			str++;
		}
	}
}
