/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniouar <aniouar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 12:19:01 by aniouar           #+#    #+#             */
/*   Updated: 2022/06/26 19:14:47 by aniouar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	**get_path_env(char **env)
{
	char	*path;
	char	*path_value;
	char	**path_env;

	path = get_path_from_env(env, "PATH");
	if (path == 0)
		custom_error("Variable Path ot found in env", 1);
	path_value = &path[ft_strpos(path, '=') + 1];
	path_env = ft_split(path_value, ':');
	return (path_env);
}
