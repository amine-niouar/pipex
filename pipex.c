/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniouar <aniouar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 07:44:50 by aniouar           #+#    #+#             */
/*   Updated: 2022/07/07 08:52:09 by aniouar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	char	***array_env;

	if (ac < 5 || ac > 5)
		custom_error("Program needs more arguments", 1);
	array_env = fill_array_env(env);
	regular_pipe(av, array_env);
	return (0);
}
