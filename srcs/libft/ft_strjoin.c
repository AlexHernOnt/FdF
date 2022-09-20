/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahernand <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 18:54:25 by ahernand          #+#    #+#             */
/*   Updated: 2019/12/27 13:44:44 by ahernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*cpy_str;

	if (!s1 || !s2)
		return (0);
	if ((str = ((char*)malloc(sizeof(char) * (ft_strlen(s1) +
		ft_strlen(s2) + 1)))) == NULL)
		return (0);
	cpy_str = str;
	if (s1)
		while (*s1 != '\0')
			*cpy_str++ = *s1++;
	if (s2)
		while (*s2 != '\0')
			*cpy_str++ = *s2++;
	*cpy_str = '\0';
	return (str);
}