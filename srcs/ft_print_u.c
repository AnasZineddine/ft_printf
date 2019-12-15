/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azineddi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:09:14 by azineddi          #+#    #+#             */
/*   Updated: 2019/10/26 20:43:07 by azineddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_header.h"

int		ft_countnumber_u(uintmax_t n)
{
	int len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

void	ft_initialize_to_zero_u(t_var *var_d)
{
	var_d->len = 0;
	var_d->read_len = 0;
	var_d->zeros_to_print = 0;
	var_d->sign_char = 0;
	var_d->spaces_to_print = 0;
	var_d->print_minus_check = 0;
	var_d->print_plus_check = 0;
	var_d->print_espace_check = 0;
}

void	count_len_u(uintmax_t n, t_var *var_d, t_format *strc)
{
	if ((n == 0 && strc->precision == -2) || (n == 0 && strc->precision == -3))
		var_d->len = 0;
	else
		var_d->len = ft_countnumber_u(n);
}

void	check_flags_one_charachter_u(t_format *strc)
{
	if (strc->precision == -1)
		strc->precision = 0;
}

void	calculate_zeros_to_print_u(t_format *strc, t_var *var_d)
{
	if (strc->precision > var_d->len)
		var_d->zeros_to_print = strc->precision - var_d->len;
	else if (strc->field_width > var_d->len && ft_strchr(strc->flags
	, '0') && strc->precision > var_d->len && !ft_strchr(strc->flags, '-'))
		var_d->zeros_to_print = strc->field_width - var_d->
		sign_char - var_d->len;
	else if (strc->field_width > var_d->len && ft_strchr(strc->
	flags, '0') && !ft_strchr(strc->flags, '-') && strc->
	precision != -2 && strc->precision > var_d->len)
		var_d->zeros_to_print = strc->field_width - var_d->
		len - var_d->sign_char;
	else if (strc->field_width > var_d->len && ft_strchr(strc->
	flags, '0') && strc->precision == 0 && !ft_strchr(strc->flags, '-'))
		var_d->zeros_to_print = strc->
		field_width - var_d->len - var_d->sign_char;
}
