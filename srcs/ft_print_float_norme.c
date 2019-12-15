/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_float_norme.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azineddi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:12:59 by azineddi          #+#    #+#             */
/*   Updated: 2019/10/26 21:27:09 by azineddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_header.h"

void	calculate_spaces_to_print_f(t_format *strc, t_var *var_d)
{
	if (strc->field_width > var_d->len && ft_strchr(strc->
flags, '-') && strc->precision >= var_d->len && strc->field_width > var_d->len)
		var_d->spaces_to_print = strc->field_width - strc->
		precision - var_d->sign_char;
	else if (strc->field_width > var_d->len && strc->precision && strc->
	precision < var_d->len && strc->field_width > strc->precision)
		var_d->spaces_to_print = strc->field_width - var_d->
		len - var_d->sign_char;
	else if (strc->field_width > var_d->len && strc->precision > var_d->
	len && !ft_strchr(strc->flags, '0') && strc->field_width > strc->precision)
		var_d->spaces_to_print = strc->field_width - strc->
		precision - var_d->sign_char;
	else if (strc->field_width > var_d->len && ft_strchr(strc->
	flags, '0') && ft_strchr(strc->flags, '-') && strc->
	field_width > strc->precision)
		var_d->spaces_to_print = strc->field_width - strc->
		precision - var_d->sign_char - var_d->len;
	else if (strc->field_width > var_d->len && strc->
	field_width > strc->precision && strc->precision)
		var_d->spaces_to_print = strc->field_width - strc->
		precision - var_d->sign_char;
	else if (strc->field_width > var_d->len && strc->
	field_width > strc->precision && !ft_strchr(strc->flags, '0'))
		var_d->spaces_to_print = strc->
		field_width - var_d->len - var_d->sign_char;
}

void	ft_print_without_minus_f(double n, t_format *strc)
{
	if (!ft_strchr(strc->flags, '-'))
	{
		ft_putnbr(n);
		ft_putstr(".00");
	}
}

void	ft_print_result_with_minus_f(double n, t_format *strc)
{
	if (ft_strchr(strc->flags, '-'))
	{
		ft_putnbr(n);
		ft_putstr(".00");
	}
	else
		ft_print_without_minus_f(n, strc);
}

int		ft_printf_float(double n, t_format *strc)
{
	t_var	var_d;

	ft_initialize_to_zero_f(&var_d);
	count_len_f(n, &var_d, strc);
	check_flags_one_charachter_f(n, strc, &var_d);
	calculate_zeros_to_print_f(strc, &var_d);
	calculate_spaces_to_print_f(strc, &var_d);
	var_d.read_len = var_d.len + var_d.zeros_to_print + var_d.
	spaces_to_print + var_d.print_espace_check + var_d.
	print_minus_check + var_d.print_plus_check;
	ft_print_result_with_minus_f(n, strc);
	return (var_d.read_len);
}
