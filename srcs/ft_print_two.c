/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azineddi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:53:16 by azineddi          #+#    #+#             */
/*   Updated: 2019/10/25 16:44:09 by azineddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_header.h"

int		ft_printf_charchter(unsigned char arg, t_format *strc)
{
	int read_len;

	read_len = 0;
	if (ft_strchr(strc->flags, '-') == 0)
	{
		while (read_len < strc->field_width - 1)
		{
			ft_putchar(' ');
			read_len++;
		}
	}
	ft_putchar(arg);
	if (ft_strchr(strc->flags, '-'))
	{
		while (read_len < strc->field_width - 1)
		{
			ft_putchar(' ');
			read_len++;
		}
	}
	read_len++;
	return (read_len);
}

void	ft_printf_string_helper(t_format *strc)
{
	if (strc->precision == -2)
		strc->precision = 0;
}

int		ft_printf_string(char *str_s, t_format *strc)
{
	int len;
	int	read_len;
	int	i;

	len = ft_strlen(str_s);
	read_len = 0;
	ft_printf_string_helper(strc);
	if (strc->precision < len && strc->precision != -1)
		len = strc->precision;
	if (!ft_strchr(strc->flags, '-'))
		while (read_len < strc->field_width - len)
		{
			ft_putchar(' ');
			read_len++;
		}
	i = 0;
	while (i < len)
		ft_putchar(str_s[i++]);
	if (ft_strchr(strc->flags, '-'))
		while (read_len < strc->field_width - len)
		{
			ft_putchar(' ');
			read_len++;
		}
	return (read_len += len);
}

int		ft_printf_pointer(long ptr, t_format *strc)
{
	int	read_len;
	int len;

	read_len = 0;
	if (ptr != 0)
		len = print_decimal_to_hex(ptr);
	else
		len = print_decimal_to_hex(ptr) + 1;
	if (ft_strchr(strc->flags, '-') == 0)
		while (read_len < strc->field_width - len - 2)
		{
			ft_putchar(' ');
			read_len++;
		}
	ft_putstr("0x");
	ft_printubase(ptr, 16, 1);
	if (ft_strchr(strc->flags, '-'))
		while (read_len < strc->field_width - len - 2)
		{
			ft_putchar(' ');
			read_len++;
		}
	return (read_len + len + 2);
}

int		print_maestro_c(t_format *strc, char arg, va_list ap)
{
	int read_len;

	read_len = 0;
	if (strc->conversion == 'c')
	{
		arg = (unsigned char)va_arg(ap, int);
		read_len = ft_printf_charchter(arg, strc);
	}
	return (read_len);
}
