/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_six.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azineddi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:59:27 by azineddi          #+#    #+#             */
/*   Updated: 2019/10/26 20:54:30 by azineddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_header.h"

void	ft_printf_core_norme5(t_format *st, char *format)
{
	if (st->conversion != '@')
		while (format[st->i] != st->conversion)
			st->i++;
}

void	ft_printf_core_norme6(t_format *st, char *forma)
{
	st->len_read += ft_printf_core_norme3(st);
	while (forma[st->i] != '%')
		st->i++;
}

int		ft_printf_core(t_format *st, char *forma, va_list ap)
{
	ft_initialise_to_zero(st);
	while (forma[st->i] != '\0')
	{
		if (forma[st->i] == '%')
		{
			grep_information(forma + st->i + 1, st);
			if (st->conversion == '@' && !ft_strchr(forma + st->i + 1, '%'))
			{
				ft_printf_free(st);
				break ;
			}
			else if (st->conversion == '@' && ft_strchr(forma + st->i + 1, '%'))
				ft_printf_core_norme6(st, forma);
			st->len_read += printing_maestro(ap, st);
			ft_printf_core_norme5(st, forma);
			ft_printf_free(st);
		}
		else
			ft_printf_core_norme4(forma, st);
		st->i++;
	}
	return (st->len_read);
}

int		ft_printf(const char *restrict format, ...)
{
	va_list		ap;
	t_format	st;
	int			len_read;

	len_read = 0;
	va_start(ap, format);
	len_read = ft_printf_core(&st, (char*)format, ap);
	va_end(ap);
	return (len_read);
}
