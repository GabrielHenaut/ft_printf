/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 17:49:29 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/06/25 00:00:18 by ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*result;
	long long int	nb;
	size_t			len;
	int				is_negative;

	is_negative = n < 0;
	nb = n;
	if (is_negative)
		nb = -nb;
	len = 1;
	while (n / 10 != 0 && len++)
		n = n / 10;
	result = malloc(sizeof(char) * (len + 1 + is_negative));
	if (!result)
		return (NULL);
	result[len + is_negative] = '\0';
	while (len-- != 0)
	{
		result[len + is_negative] = nb % 10 + '0';
		nb /= 10;
	}
	if (is_negative)
		result[0] = '-';
	return (result);
}
