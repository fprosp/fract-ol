/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:24:15 by fprosper          #+#    #+#             */
/*   Updated: 2022/04/19 17:20:17 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s1_len;
	char	*nstr;

	if (!s1 || !set)
	{
		return (NULL);
	}
	while (*s1 && ft_strchr(set, *s1))
	{
		s1++;
	}
	s1_len = ft_strlen(s1);
	while (s1_len && ft_strchr(set, *(s1 + s1_len)))
	{
		s1_len--;
	}
	nstr = ft_substr(s1, 0, s1_len + 1);
	return (nstr);
}
