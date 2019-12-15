/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x_norme.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azineddi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:19:14 by azineddi          #+#    #+#             */
/*   Updated: 2019/11/02 16:32:07 by azineddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_header.h"

void	calculate_spaces_to_print_x(t_format *strc, t_var *var_d)
{
	if (strc->field_width > var_d->len && ft_strchr(strc->flags, '-') && strc->
	precision > var_d->len && strc->field_width > strc->precision)
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
	else if (strc->field_width > var_d->len && ft_strchr(
	strc->flags, '0') && ft_strchr(
	strc->flags, '-') && strc->field_width > strc->precision)
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

void	ft_print_minus_norme(t_var *var_d)
{
	ft_putstr("0x");
	var_d->read_len++;
}

void	ft_print_without_minus_x(uintmax_t n, t_format *strc, t_var *var_d)
{
	if (!ft_strchr(strc->flags, '-'))
	{
		while (var_d->spaces_to_print--)
			ft_putchar(' ');
		if (var_d->print_minus_check)
		{
			ft_putchar('-');
			n = -n;
		}
		if (var_d->print_espace_check)
			ft_putchar(' ');
		else if (n != 0 && var_d->print_plus_check)
			ft_print_minus_norme(var_d);
		while (var_d->zeros_to_print--)
			ft_putchar('0');
		if (n == 0 && strc->precision != -2 && strc->precision != -3)
			ft_putnbr(0);
		else if (n == 0 && strc->precision == 0)
			ft_putnbr(0);
		else if (n != 0)
			ft_printubase(n, 16, 1);
	}
}

void	ft_print_result_with_minus_x(uintmax_t n, t_format *strc, t_var *var_d)
{
	if (ft_strchr(strc->flags, '-'))
	{
		if (var_d->print_minus_check)
		{
			ft_putchar('-');
			n = -n;
		}
		if (var_d->print_espace_check)
			ft_putchar(' ');
		else if (n != 0 && var_d->print_plus_check)
			ft_print_minus_norme(var_d);
		while (var_d->zeros_to_print--)
			ft_putchar('0');
		if (n == 0 && strc->precision != -2 && strc->precision != -3)
			ft_putnbr(0);
		else if (n == 0 && strc->precision == 0)
			ft_putnbr(0);
		else if (n != 0)
			ft_printubase(n, 16, 1);
		while (var_d->spaces_to_print--)
			ft_putchar(' ');
	}
	else
		ft_print_without_minus_x(n, strc, var_d);
}

int		ft_printf_x(uintmax_t n, t_format *strc)
{
	t_var	var_d;

	ft_initialize_to_zero_x(&var_d);
	count_len_x(n, &var_d, strc);
	check_flags_one_charachter_x(n, strc, &var_d);
	calculate_zeros_to_print_x(strc, &var_d);
	calculate_spaces_to_print_x(strc, &var_d);
	var_d.read_len = var_d.len + var_d.zeros_to_print + var_d.
	spaces_to_print + var_d.print_espace_check + var_d.
	print_minus_check + var_d.print_plus_check;
	ft_print_result_with_minus_x(n, strc, &var_d);
	return (var_d.read_len);
}
