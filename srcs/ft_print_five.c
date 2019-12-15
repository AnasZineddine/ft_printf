/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_five.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azineddi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:57:25 by azineddi          #+#    #+#             */
/*   Updated: 2019/10/25 17:05:11 by azineddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_header.h"

int		ft_printf_core_norme2(t_format *st)
{
	int len_read;

	len_read = 0;
	ft_putchar('%');
	len_read++;
	if (st->field_width != 0)
	{
		st->field_width--;
		while (st->field_width--)
		{
			ft_putchar(' ');
			len_read++;
		}
	}
	return (len_read);
}

int		ft_printf_core_norme3(t_format *st)
{
	int len_read;

	len_read = 0;
	if (!ft_strchr(st->flags, '-'))
		len_read += ft_printf_core_norme(st);
	else
		len_read += ft_printf_core_norme2(st);
	st->i++;
	return (len_read);
}

void	ft_printf_core_norme4(const char *restrict format, t_format *st)
{
	ft_putchar(format[st->i]);
	st->len_read++;
}

void	ft_printf_free(t_format *st)
{
	free(st->flags);
	free(st->conversion_flags);
}

void	ft_initialise_to_zero(t_format *st)
{
	st->i = 0;
	st->len_read = 0;
}
