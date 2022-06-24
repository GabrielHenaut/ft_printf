/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 20:12:09 by ghenaut-          #+#    #+#             */
/*   Updated: 2022/06/24 06:41:49 by Ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define STDOUT 1

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include "../libft/libft.h"

typedef struct s_rtn_str{
	int		size;
	char	*str;
}	t_rtn_str;

int		ft_printf(const char *fmt, ...);
int		ft_vprintf(const char *fmt, va_list args);
void	generate_rtn_str(const char *fmt, va_list args, t_rtn_str *rtn);
void	append_to_str(t_rtn_str *rtn, char c);
void	parse_arg(char c, va_list args, t_rtn_str *rtn);
void	add_str(t_rtn_str *rtn, char *str);
void	add_nbr_base(size_t nbr, const char *base, t_rtn_str *rtn);
void	add_nbr(int nbr, t_rtn_str *rtn);
void	add_unbr(unsigned int nbr, t_rtn_str *rtn);
void	add_xnbr(unsigned int nbr, t_rtn_str *rtn);
void	add_xnbr_up(unsigned int nbr, t_rtn_str *rtn);
void	add_addr(void *nbr, t_rtn_str *rtn);

#endif