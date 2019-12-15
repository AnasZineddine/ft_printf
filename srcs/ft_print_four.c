/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_four.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azineddi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:56:20 by azineddi          #+#    #+#             */
/*   Updated: 2019/10/26 20:55:12 by azineddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_header.h"

int		print_maestro_x(t_format *strc, uintmax_t num, va_list ap)
{
	int read_len;

	read_len = 0;
	if (strc->conversion == 'x')
	{
		num = va_arg(ap, uintmax_t);
		if (strc->conversion_flags == NULL)
			read_len = ft_printf_x((unsigned)num, strc);
		else if (ft_strchr(strc->conversion_flags, 'h') && ft_strstr(
			strc->conversion_flags, "hh") == NULL)
			read_len = ft_printf_x((unsigned short)num, strc);
		else if (ft_strstr(strc->conversion_flags, "hh") != NULL)
			read_len = ft_printf_x((unsigned char)num, strc);
		else if (ft_strchr(strc->conversion_flags, 'l') && ft_strstr(
			strc->conversion_flags, "ll") == NULL)
			read_len = ft_printf_x((unsigned long)num, strc);
		else if (ft_strstr(strc->conversion_flags, "ll") != NULL)
			read_len = ft_printf_x((unsigned long long)num, strc);
	}
	return (read_len);
}

int		print_maestro_capx(t_format *strc, uintmax_t num, va_list ap)
{
	int read_len;

	read_len = 0;
	if (strc->conversion == 'X')
	{
		num = va_arg(ap, uintmax_t);
		if (strc->conversion_flags == NULL)
			read_len = ft_printf_capx((unsigned)num, strc);
		else if (ft_strchr(strc->conversion_flags, 'h') && ft_strstr(
			strc->conversion_flags, "hh") == NULL)
			read_len = ft_printf_capx((unsigned short)num, strc);
		else if (ft_strstr(strc->conversion_flags, "hh") != NULL)
			read_len = ft_printf_capx((unsigned char)num, strc);
		else if (ft_strchr(strc->conversion_flags, 'l') && ft_strstr(
			strc->conversion_flags, "ll") == NULL)
			read_len = ft_printf_capx((unsigned long)num, strc);
		else if (ft_strstr(strc->conversion_flags, "ll") != NULL)
			read_len = ft_printf_capx((unsigned long long)num, strc);
	}
	return (read_len);
}

int		print_maestro_f(t_format *strc, uintmax_t num, va_list ap)
{
	int read_len;

	read_len = 0;
	if (strc->conversion == 'f')
	{
		num = va_arg(ap, double);
		if (strc->conversion_flags == NULL || ft_strchr(
			strc->conversion_flags, 'l'))
			read_len = ft_printf_float(num, strc);
		else if (ft_strchr(strc->conversion_flags, 'L'))
			read_len = ft_printf_float((long double)num, strc);
	}
	return (read_len);
}

int		printing_maestro(va_list ap, t_format *strc)
{
	char			arg;
	int				read_len;
	char			*str_s;
	long			ptr;
	uintmax_t		num;

	read_len = 0;
	arg = '\0';
	str_s = NULL;
	ptr = 0;
	num = 0;
	read_len += print_maestro_c(strc, arg, ap);
	read_len += print_maestro_s(strc, str_s, ap);
	read_len += print_maestro_p(strc, ptr, ap);
	read_len += print_maestro_d(strc, num, ap);
	read_len += print_maestro_o(strc, num, ap);
	read_len += print_maestro_u(strc, num, ap);
	read_len += print_maestro_x(strc, num, ap);
	read_len += print_maestro_capx(strc, num, ap);
	read_len += print_maestro_f(strc, num, ap);
	return (read_len);
}

int		ft_printf_core_norme(t_format *st)
{
	int len_read;

	len_read = 0;
	if (!ft_strchr(st->flags, '-'))
	{
		if (st->field_width != 0)
		{
			st->field_width--;
			while (st->field_width--)
			{
				ft_putchar(' ');
				len_read++;
			}
		}
		ft_putchar('%');
		len_read++;
	}
	return (len_read);
}
