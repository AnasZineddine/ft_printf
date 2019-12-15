/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azineddi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 16:28:59 by azineddi          #+#    #+#             */
/*   Updated: 2018/10/25 12:31:44 by azineddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*cpy;

	i = 0;
	len = ft_strlen(s1);
	cpy = (char*)malloc(sizeof(char) * (len + 1));
	if (cpy == NULL)
	{
		return (cpy);
	}
	else
	{
		while (i <= len)
		{
			cpy[i] = s1[i];
			i++;
		}
		return (cpy);
	}
}
