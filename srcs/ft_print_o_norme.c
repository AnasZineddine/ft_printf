/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_o_norme.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azineddi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:14:49 by azineddi          #+#    #+#             */
/*   Updated: 2019/11/02 16:31:28 by azineddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_header.h"

void	calculate_spaces_to_print_o(t_format *strc, t_var *var_d)
{
	if (strc->field_width > var_d->len && ft_strchr(
	strc->flags, '-') && strc->precision > var_d->len && strc->
	field_width > strc->precision)
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
	strc->flags, '0') && ft_strchr(strc->flags, '-') && strc->
	field_width > strc->precision)
		var_d->spaces_to_print = strc->field_width - strc->
		precision - var_d->sign_char - var_d->len;
	else if (strc->field_width > var_d->len && strc->field_width > strc->
	precision && strc->precision)
		var_d->spaces_to_print = strc->field_width - strc->
		precision - var_d->sign_char;
	else if (strc->field_width > var_d->len && strc->
	field_width > strc->precision && !ft_strchr(strc->flags, '0'))
		calculate_norme(strc, var_d);
}

void	ft_print_without_minus_o(uintmax_t n, t_format *strc, t_var *var_d)
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
		else if ((n == 0 && var_d->print_plus_check && strc->
		precision == -2) || (n != 0 && var_d->print_plus_check && strc->
		precision < var_d->len))
			ft_putchar('0');
		while (var_d->zeros_to_print--)
			ft_putchar('0');
		if ((n == 0 && strc->precision != -2 && strc->
		precision != -3) || (n == 0 && strc->precision == -3 && var_d->
		print_plus_check))
			ft_putnbr(0);
		else if (n != 0)
			ft_printubase(n, 8, 1);
	}
}

void	ft_print_result_with_minus_o(uintmax_t n, t_format *strc, t_var *var_d)
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
		else if ((n == 0 && var_d->print_plus_check && strc->
		precision == -2) || (n != 0 && var_d->print_plus_check && strc->
		precision < var_d->len))
			ft_putchar('0');
		while (var_d->zeros_to_print--)
			ft_putchar('0');
		if (n == 0 && strc->precision != -2 && strc->precision != -3)
			ft_putnbr(0);
		else if (n != 0)
			ft_printubase(n, 8, 1);
		while (var_d->spaces_to_print--)
			ft_putchar(' ');
	}
	else
		ft_print_without_minus_o(n, strc, var_d);
}

int		ft_printf_o(uintmax_t n, t_format *strc)
{
	t_var	var_d;

	ft_initialize_to_zero_o(&var_d);
	count_len_o(n, &var_d, strc);
	check_flags_one_charachter_o(n, strc, &var_d);
	calculate_zeros_to_print_o(strc, &var_d);
	calculate_spaces_to_print_o(strc, &var_d);
	var_d.read_len = var_d.len + var_d.zeros_to_print + var_d.
	spaces_to_print + var_d.print_espace_check + var_d.
	print_minus_check + var_d.print_plus_check;
	ft_print_result_with_minus_o(n, strc, &var_d);
	return (var_d.read_len);
}
