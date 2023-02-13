/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprosper <fprosper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 17:21:50 by fprosper          #+#    #+#             */
/*   Updated: 2022/05/04 10:59:10 by fprosper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	np_gen(const char *s, char c)
{
	size_t	i;
	size_t	np;

	i = 0;
	np = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			np++;
		i++;
	}
	return (np);
}

size_t	info_s_gen(const char *s, char c, size_t **info_s, size_t *j)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			l++;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			info_s[*j] = (size_t *)malloc(sizeof(size_t) * 2);
			if (!info_s[*j])
				return (0);
			i++;
			info_s[*j][1] = i - l;
			info_s[*j][0] = l;
			*j += 1;
			l = 0;
			i = i - 1;
		}
		i++;
	}
	return (1);
}

void	new_arr_gen(char const *s, char **new_array, size_t **info_s, size_t np)
{
	size_t	i;

	i = 0;
	while (i < np)
	{
		new_array[i] = ft_substr(s, info_s[i][1], info_s[i][0]);
		free(info_s[i]);
		i++;
	}
	free(info_s);
	new_array[i] = NULL;
}

char	**ft_split(char const *s, char c)
{
	size_t	j;
	size_t	np;
	size_t	**info_s;
	char	**new_array;

	if (!s)
		return (NULL);
	np = np_gen(s, c);
	new_array = (char **)malloc((np + 1) * sizeof(char *));
	if (!new_array)
		return (NULL);
	info_s = (size_t **)malloc(np * sizeof(size_t *));
	if (!info_s)
		return (NULL);
	j = 0;
	if (info_s_gen(s, c, info_s, &j) == 0)
		return (NULL);
	else
	{
		new_arr_gen(s, new_array, info_s, np);
		return (new_array);
	}
}
