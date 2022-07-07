/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniouar <aniouar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:54:12 by aniouar           #+#    #+#             */
/*   Updated: 2022/06/24 22:02:47 by aniouar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	len_of_arrays(char **srcs)
{
	int	i;

	i = 0;
	while (srcs[i])
	{
		i++;
	}
	return (i);
}

int	get_total_len(char **paths)
{
	int	i;
	int	total;

	total = 0;
	i = -1;
	while (paths[++i])
		total += ft_strlen(paths[i]);
	return (total);
}

int	max_len_tab(char **strs)
{
	int	i;
	int	len;
	int	max;

	len = 0;
	max = 0;
	i = -1;
	while (strs[++i])
	{
		len = ft_strlen(strs[i]);
		if (max < len)
			max = len;
	}
	return (max);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
