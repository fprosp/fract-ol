/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 19:19:25 by fprosper          #+#    #+#             */
/*   Updated: 2022/04/11 19:19:42 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	secondo_caso(const char *s, unsigned int start)
{
	unsigned int	i;

	i = 0;
	while (i + start < ft_strlen(s))
		i++;
	return (i);
}

void	subs_alloc(const char *s, unsigned int start, char *subs, size_t len)
{
	unsigned int	i;

	i = 0;
	while (i < len)
	{
		*(subs + i) = *(s + start + i);
		i++;
	}
	*(subs + i) = '\0';
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		subs = (char *)malloc(sizeof(char) * 1);
		if (!subs)
			return (NULL);
		*(subs) = '\0';
		return (subs);
	}
	if (ft_strlen(s) - start < len)
		len = secondo_caso(s, start);
	subs = (char *)malloc(sizeof(char) * (len + 1));
	if (!subs)
		return (NULL);
	subs_alloc (s, start, subs, len);
	return (subs);
}
