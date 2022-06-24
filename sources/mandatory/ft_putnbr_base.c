/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 18:51:43 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/06/24 06:42:52 by Ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_nbr_size(size_t nbr, int base_size)
{
	int	nbr_size;

	nbr_size = 1;
	while (nbr / base_size > 0)
	{
		nbr /= base_size;
		nbr_size++;
	}
	return (nbr_size);
}

void	add_nbr_base(size_t nbr, const char *base, t_rtn_str *rtn)
{
	int		base_size;
	int		nbr_size;
	char	*nbr_str;

	base_size = ft_strlen(base);
	nbr_size = get_nbr_size(nbr, base_size);
	nbr_str = ft_calloc(nbr_size + 1, sizeof (char));
	if (nbr_str == NULL)
		return ;
	while (nbr != 0 || nbr_size >= 1)
	{
		nbr_str[--nbr_size] = base[nbr % base_size];
		nbr /= base_size;
	}
	add_str(rtn, nbr_str);
	free(nbr_str);
}
