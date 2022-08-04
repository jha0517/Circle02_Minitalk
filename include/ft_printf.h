/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyujung <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 19:12:18 by hyujung           #+#    #+#             */
/*   Updated: 2022/02/01 21:11:40 by hyujung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define ENDSYMBOL "cspdiuxX%"
# include <stdarg.h>

typedef struct s_print
{
	va_list	args;
	int		nprinted;
	int		perc;
}t_print;

int		ft_printf(const char *str, ...);
int		ft_eval_format(t_print *tab, const char *str, int pos);
int		ft_convert_indicator(t_print *tab, const char *str, int pos);
t_print	*ft_initialize_tab(t_print *tab);
char	*ft_tolowerstr(char *str);
void	ft_final_alignement_i(t_print *tab, int i);
void	ft_print_char(t_print *tab);
void	ft_print_percent(t_print *tab);
void	ft_print_integer(t_print *tab);
void	ft_print_tab(t_print *tab);
void	ft_print_str(t_print *tab);
void	ft_print_address(t_print *tab);
void	ft_print_uinteger(t_print *tab);
void	ft_print_hex(t_print *tab, char c);
char	*ft_utoa(unsigned long long llu);
char	*ft_utoa_base(unsigned long long llu, char *base);
#endif
