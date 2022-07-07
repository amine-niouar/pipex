/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniouar <aniouar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:05:43 by aniouar           #+#    #+#             */
/*   Updated: 2022/07/06 01:28:23 by aniouar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_substr(char *s, unsigned int start, size_t len, int mod)
{
	int		x;
	char	*dst;

	if (!s)
		return (0);
	dst = malloc(len + 1);
	if (!dst)
		return (0);
	len += start;
	x = 0;
	while (start < len && s[start] != '\0')
	{
		dst[x] = s[start];
		x++;
		start++;
	}
	dst[x] = '\0';
	if (mod)
	{
		free(s);
		s = 0;
	}
	return (dst);
}

int	count_words(const char *s, int c)
{
	int	i;
	int	start;
	int	count;

	count = 0;
	start = -1;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && start == -1)
			start = i;
		if (s[i] == c && start != -1)
		{
			count++;
			start = -1;
		}
		i++;
	}
	if ((s[i] == c && ft_strlen(s) > 0) || start != -1)
		count++;
	return (count);
}

int	fill_split(char **t, char *s, char c)
{
	int	i;
	int	start;
	int	x;

	x = 0;
	start = -1;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && start == -1)
			start = i;
		if (s[i] == c && start != -1)
		{
			t[x++] = ft_substr(s, start, (i - start), 0);
			start = -1;
		}
		i++;
	}
	if ((s[i] == c && ft_strlen(s) > 0) || start != -1)
		t[x++] = ft_substr(s, start, (ft_strlen(s) - start), 0);
	return (x);
}

char	**ft_split(char *s, char c)
{
	int		count;
	char	**t;
	int		x;

	if (!s)
		return (NULL);
	count = count_words(s, c);
	t = (char **)malloc(sizeof(char *) * (count + 1));
	if (!t)
		return (NULL);
	x = fill_split(t, s, c);
	t[x] = 0;
	return (t);
}
