/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azineddi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:54:48 by azineddi          #+#    #+#             */
/*   Updated: 2019/10/25 16:43:58 by azineddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_header.h"

int		print_maestro_s(t_format *strc, char *str_s, va_list ap)
{
	int read_len;

	read_len = 0;
	if (strc->conversion == 's')
	{
		str_s = check_str(va_arg(ap, char*));
		read_len = ft_printf_string(str_s, strc);
		free(str_s);
	}
	return (read_len);
}

int		print_maestro_p(t_format *strc, long ptr, va_list ap)
{
	int read_len;

	read_len = 0;
	if (strc->conversion == 'p')
	{
		ptr = va_arg(ap, long);
		read_len = ft_printf_pointer(ptr, strc);
	}
	return (read_len);
}

int		print_maestro_d(t_format *strc, uintmax_t num, va_list ap)
{
	int read_len;

	read_len = 0;
	if (strc->conversion == 'd' || strc->conversion == 'i')
	{
		num = va_arg(ap, intmax_t);
		if (strc->conversion_flags == NULL)
			read_len = ft_printf_d((int)num, strc);
		else if (ft_strchr(strc->conversion_flags, 'h') && ft_strstr(
			strc->conversion_flags, "hh") == NULL)
			read_len = ft_printf_d((short)num, strc);
		else if (ft_strstr(strc->conversion_flags, "hh") != NULL)
			read_len = ft_printf_d((char)num, strc);
		else if (ft_strchr(strc->conversion_flags, 'l') && ft_strstr(
			strc->conversion_flags, "ll") == NULL)
			read_len = ft_printf_d((long int)num, strc);
		else if (ft_strstr(strc->conversion_flags, "ll") != NULL)
			read_len = ft_printf_d((long long int)num, strc);
	}
	return (read_len);
}

int		print_maestro_o(t_format *strc, uintmax_t num, va_list ap)
{
	int read_len;

	read_len = 0;
	if (strc->conversion == 'o')
	{
		num = va_arg(ap, uintmax_t);
		if (strc->conversion_flags == NULL)
			read_len = ft_printf_o((unsigned)num, strc);
		else if (ft_strchr(strc->conversion_flags, 'h') && ft_strstr(
			strc->conversion_flags, "hh") == NULL)
			read_len = ft_printf_o((unsigned short)num, strc);
		else if (ft_strstr(strc->conversion_flags, "hh") != NULL)
			read_len = ft_printf_o((unsigned char)num, strc);
		else if (ft_strchr(strc->conversion_flags, 'l') && ft_strstr(
			strc->conversion_flags, "ll") == NULL)
			read_len = ft_printf_o((unsigned long)num, strc);
		else if (ft_strstr(strc->conversion_flags, "ll") != NULL)
			read_len = ft_printf_o((unsigned long long)num, strc);
	}
	return (read_len);
}

int		print_maestro_u(t_format *strc, uintmax_t num, va_list ap)
{
	int read_len;

	read_len = 0;
	if (strc->conversion == 'u')
	{
		num = va_arg(ap, uintmax_t);
		if (strc->conversion_flags == NULL)
			read_len = ft_printf_u((unsigned)num, strc);
		else if (ft_strchr(strc->conversion_flags, 'h') && ft_strstr(
			strc->conversion_flags, "hh") == NULL)
			read_len = ft_printf_u((unsigned short)num, strc);
		else if (ft_strstr(strc->conversion_flags, "hh") != NULL)
			read_len = ft_printf_u((unsigned char)num, strc);
		else if (ft_strchr(strc->conversion_flags, 'l') && ft_strstr(
			strc->conversion_flags, "ll") == NULL)
			read_len = ft_printf_u((unsigned long)num, strc);
		else if (ft_strstr(strc->conversion_flags, "ll") != NULL)
			read_len = ft_printf_u((unsigned long long)num, strc);
	}
	return (read_len);
}
