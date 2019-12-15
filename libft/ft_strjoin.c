/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azineddi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 16:53:33 by azineddi          #+#    #+#             */
/*   Updated: 2018/10/23 14:47:10 by azineddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str_mem;
	size_t	len;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str_mem = ft_strnew(len);
	if (!str_mem)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		str_mem[i] = (char)s1[i];
		i++;
	}
	j = 0;
	while (i < len && j < ft_strlen(s2))
	{
		str_mem[i++] = (char)s2[j++];
	}
	str_mem[i] = '\0';
	return (str_mem);
}
