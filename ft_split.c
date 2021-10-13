/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yironmak <yironmak@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 12:00:09 by yironmak          #+#    #+#             */
/*   Updated: 2021/10/12 13:53:11 by yironmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	static	count_substrings(char const *s, char c)
{
	int		count;
	size_t	i;

	i = 0;
	while (s[i] == c)
		i++;
	if (s[i] != c)
	{
		count = 1;
		while (s[i] && s[i] != c)
			i++;
	}
	while (s[i] && i < ft_strlen(s))
	{
		if (s[i] == c && s[i + 1] && s[i + 1] != c)
		{
			count++;
			while (s[i] == c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = -1;
	if (!s)
		return (NULL);
	strs = (char **)malloc(sizeof(char *) * (count_substrings(s, c) + 1));
	while (strs && i < (int)ft_strlen(s))
	{
		len = 0;
		while (s[i] != c && s[i])
		{
			len++;
			i++;
		}
		i++;
		if (len > 0)
			strs[++j] = ft_substr(s, i - len - 1, len);
	}
	if (strs != NULL)
		strs[++j] = 0;
	return (strs);
}
