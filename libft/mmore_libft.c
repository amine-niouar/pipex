/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mmore_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniouar <aniouar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 16:23:23 by aniouar           #+#    #+#             */
/*   Updated: 2022/07/06 01:28:34 by aniouar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strcat(char *dest, char *src)
{
	int	index;
	int	i;

	index = 0;
	while (dest[index] != '\0')
		index++;
	i = 0;
	while (src[i] != '\0')
		dest[index++] = src[i++];
	dest[index] = '\0';
	return (dest);
}

int	ft_append(char *dst, const char *src, int index)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[index] = src[i];
		i++;
		index++;
	}
	return (index);
}

char	*ft_strjoin(char *s1, char *s2, int mod)
{
	size_t	len;
	char	*s;
	int		index;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	s = malloc(len * sizeof(char));
	if (s != 0)
	{
		index = 0;
		index = ft_append(s, s1, index);
		index = ft_append(s, s2, index);
		s[index] = '\0';
		if (mod)
			free (s1);
		return (s);
	}
	return (0);
}

void	ft_putstr_endl(int fd, char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		write(fd, &s[i], 1);
	write(fd, "\n", 1);
}
