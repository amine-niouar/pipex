/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniouar <aniouar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 18:42:20 by aniouar           #+#    #+#             */
/*   Updated: 2022/07/06 01:16:01 by aniouar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	link_nodes(t_cmd **previous, t_cmd **current)
{
	(*previous)->next = (*current);
	(*current)->previous = (*previous);
}

void	fill_current(t_cmd **current, char *cmd, char **path_env)
{
	char	*ccmd;

	(*current)->options = ft_split(cmd, 32);
	ccmd = (*current)->options[0];
	if (ft_strlen(cmd) == 0)
		(*current)->correct_path = 0;
	else
		(*current)->correct_path = get_correct_path(path_env, ccmd);
	(*current)->next = 0;
	(*current)->previous = 0;
}
