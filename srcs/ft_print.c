/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variadic_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azineddi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 14:18:53 by azineddi          #+#    #+#             */
/*   Updated: 2019/10/25 16:33:15 by azineddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_header.h"

char	*grep_flags(char **format)
{
	int		i;
	char	*str;
	char	*str_flags;

	str = *format;
	i = 0;
	while (str[i] == '0' || str[i] == ' ' || str[i] == '#' || str
[i] == '+' || str[i] == '-')
		i++;
	str_flags = ft_strnew(i);
	i = 0;
	while (*str == '0' || *str == ' ' || *str == '#'
	|| *str == '+' || *str == '-')
	{
		str_flags[i] = *str;
		i++;
		str++;
	}
	*format = str;
	return (str_flags);
}

int		grep_field_width(char **format)
{
	char	*str_fw;
	int		nbr;

	str_fw = *format;
	nbr = 0;
	if (ft_isdigit(*str_fw))
	{
		nbr = ft_atoi(str_fw);
		while (ft_isdigit(*str_fw))
			str_fw++;
		*format = str_fw;
	}
	return (nbr);
}

int		grep_precision(char **format)
{
	char	*str_p;
	int		nbr;

	str_p = *format;
	nbr = -1;
	if (*str_p == '.')
	{
		str_p++;
		if (ft_isdigit(*str_p))
		{
			nbr = ft_atoi(str_p);
			if (nbr == 0)
				nbr = -3;
		}
		else
			nbr = -2;
		while (ft_isdigit(*str_p))
			str_p++;
		*format = str_p;
	}
	return (nbr);
}

char	*grep_conversion_flags(char **format)
{
	char	*str_cf;
	char	*str;
	int		i;

	str_cf = NULL;
	str = *format;
	i = 0;
	while (str[i] == 'h' || str[i] == 'l' || str[i] == 'L')
		i++;
	if (i == 0)
		return (NULL);
	str_cf = ft_strnew(i);
	i = 0;
	while (*str == 'h' || *str == 'l' || *str == 'L')
	{
		str_cf[i] = *str;
		i++;
		str++;
	}
	*format = str;
	return (str_cf);
}

char	grep_conversion(char **format)
{
	char *str_c;
	char c;

	c = '@';
	str_c = *format;
	if (ft_isalpha(*str_c))
	{
		c = *str_c;
		str_c++;
		*format = str_c;
	}
	return (c);
}
