/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   her_doc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniouar <aniouar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 13:44:08 by aniouar           #+#    #+#             */
/*   Updated: 2022/07/06 19:03:36 by aniouar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	heredoc_check(int ac, char **av, t_bash **bash)
{
	(*bash)->herdoc = malloc(sizeof(t_herdoc));
	if (!(*bash)->herdoc)
		custom_error("Memory Allocation", 1);
	(*bash)->herdoc->status = 0;
	(*bash)->herdoc->tempo = 0;
	if (ft_strcmp(av[1], "here_doc") == 0)
	{
		(*bash)->herdoc->status = 1;
		if (ac < 6)
			custom_error("invalid arguments", 1);
	}
}

void	herdoc_route(char **av, t_bash **bash)
{
	int		fd;
	char	*s;
	char	*flex_limiter;

	(*bash)->herdoc->tempo = ft_strdup("/tmp/.tempo.txt");
	(*bash)->herdoc->status = 1;
	fd = open("/tmp/.tempo.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
	{
		perror ("");
		exit (1);
	}
	flex_limiter = ft_strjoin(av[2], "\n", 0);
	s = get_next_line(0);
	while (ft_strcmp(s, flex_limiter) != 0)
	{
		write(fd, s, ft_strlen(s));
		free(s);
		s = get_next_line(0);
	}
	free(flex_limiter);
	close(fd);
	free(s);
}

void	herdoc_main(char **av, t_bash **bash)
{
	if ((*bash)->herdoc->status)
		herdoc_route(av, bash);
}
