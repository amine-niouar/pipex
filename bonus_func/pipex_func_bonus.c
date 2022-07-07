/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_func_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniouar <aniouar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 08:02:01 by aniouar           #+#    #+#             */
/*   Updated: 2022/07/06 01:15:30 by aniouar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free (tab[i]);
	free (tab);
}

void	init_vars(t_cmd **head, t_cmd **current, t_cmd **prev)
{
	*head = 0;
	*current = 0;
	*prev = 0;
}

t_cmd	*fill_cmds(int ac, char **av, char **env, int range)
{
	int		i;
	t_cmd	*head;
	t_cmd	*current;
	t_cmd	*previous;
	char	**path_env;

	path_env = get_path_env(env);
	init_vars(&head, &current, &previous);
	i = range - 1;
	while (++i < (ac - 1))
	{
		current = malloc(sizeof(t_cmd));
		if (!current)
			custom_error("Memory Allocation", 1);
		fill_current(&current, av[i], path_env);
		if (!head)
			head = current;
		else
			link_nodes(&previous, &current);
		previous = current;
	}
	if (current)
		current->next = 0;
	free_tab(path_env);
	return (head);
}

int	len_cmds(t_cmd *cmd)
{
	int	len;

	len = 0;
	while (cmd != 0)
	{
		len++;
		cmd = cmd->next;
	}
	return (len);
}
