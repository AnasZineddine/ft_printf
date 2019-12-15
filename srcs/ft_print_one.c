/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_one.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azineddi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:51:33 by azineddi          #+#    #+#             */
/*   Updated: 2019/10/26 20:56:16 by azineddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_header.h"

void	grep_information(char *format, t_format *strc)
{
	strc->flags = grep_flags(&format);
	strc->field_width = grep_field_width(&format);
	strc->precision = grep_precision(&format);
	strc->conversion_flags = grep_conversion_flags(&format);
	strc->conversion = grep_conversion(&format);
}

char	*check_str(char *str)
{
	if (str)
		return (ft_strdup(str));
	else
		return (ft_strdup("(null)"));
}

void	ft_printubase(uintmax_t num, unsigned int base, int is_lower)
{
	static char	*base_str;

	base_str = "0123456789abcdef";
	if (num >= base)
		ft_printubase(num / base, base, is_lower);
	if (is_lower)
	{
		ft_putchar(base_str[num % base]);
	}
	else
	{
		ft_putchar((char)ft_toupper(base_str[num % base]));
	}
}

int		print_decimal_to_hex(uintmax_t n)
{
	char	hexa_tab[100];
	int		i;
	int		temp;
	int		len;

	len = 0;
	i = 0;
	temp = 0;
	while (n > 0)
	{
		temp = n % 16;
		if (temp < 10)
			hexa_tab[i++] = temp + 48;
		else
			hexa_tab[i++] = temp + 55;
		n = n / 16;
	}
	i -= 1;
	while (i-- >= 0)
		len++;
	return (len);
}

int		print_decimal_to_octal(uintmax_t n)
{
	int	len;
	int	i;
	int octalnumber[100];

	len = 0;
	i = 1;
	while (n != 0)
	{
		octalnumber[i++] = n % 8;
		n = n / 8;
	}
	i = i - 1;
	while (i-- > 0)
		len++;
	return (len);
}
