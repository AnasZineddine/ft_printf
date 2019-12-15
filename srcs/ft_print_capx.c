/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_capx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azineddi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 21:38:03 by azineddi          #+#    #+#             */
/*   Updated: 2019/10/25 16:34:07 by azineddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_header.h"

void	ft_initialize_to_zero_capx(t_var *var_d)
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

void	count_len_capx(uintmax_t n, t_var *var_d, t_format *strc)
{
	if ((n == 0 && strc->precision == -2) || (n == 0 && strc->precision == -3))
		var_d->len = 0;
	else if (n == 0 && strc->precision != -2)
		var_d->len++;
	else
	{
		var_d->len = print_decimal_to_hex(n);
	}
}

void	check_flags_one_char_capx(uintmax_t n, t_format *strc, t_var *var_d)
{
	if (strc->precision == -1)
		strc->precision = 0;
	if (ft_strchr(strc->flags, '#') && n != 0)
	{
		var_d->sign_char++;
		var_d->sign_char++;
		var_d->print_plus_check = 1;
	}
}

void	calculate_zeros_to_print_capx(t_format *strc, t_var *var_d)
{
	if (strc->precision > var_d->len)
		var_d->zeros_to_print = strc->precision - var_d->len;
	else if (strc->field_width > var_d->len && ft_strchr(strc->flags
	, '0') && strc->precision > var_d->len && !ft_strchr(strc->flags, '-'))
		var_d->zeros_to_print = strc->field_width - var_d->
	sign_char - var_d->len;
	else if (strc->field_width > var_d->
	len && ft_strchr(
	strc->flags, '0') && !ft_strchr(
	strc->flags, '-') && strc->precision != -2 && strc->precision > var_d->len)
		var_d->zeros_to_print = strc->field_width - var_d->
	len - var_d->sign_char;
	else if (strc->field_width > var_d->len && ft_strchr(
	strc->flags, '0') && strc->precision == 0 && !ft_strchr(strc->flags, '-'))
		var_d->zeros_to_print = strc->
	field_width - var_d->len - var_d->sign_char;
}
