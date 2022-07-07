/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_proc_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniouar <aniouar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 19:23:01 by aniouar           #+#    #+#             */
/*   Updated: 2022/07/07 09:14:23 by aniouar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	first_proc(int ***cfds, int pos, char *infile)
{
	int	fd;
	int	**fds;

	fds = *cfds;
	fd = open(infile, O_RDONLY);
	catch_bad_fd(fd);
	dup2(fd, STDIN_FILENO);
	close(fd);
	close(fds[pos][0]);
	dup2(fds[pos][1], STDOUT_FILENO);
	close(fds[pos][1]);
}

void	medium_proc(int ***cfds, int pos)
{
	int	**fds;

	pos -= 1;
	fds = *cfds;
	dup2(fds[pos][0], STDIN_FILENO);
	close(fds[pos][0]);
	dup2(fds[pos + 1][1], STDOUT_FILENO);
	close(fds[pos + 1][1]);
}

void	last_proc(int ***cfds, int pos, char *outfile, int mod)
{
	int	fd;
	int	**fds;

	fds = *cfds;
	pos -= 1;
	if (!mod)
		fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else
		fd = open(outfile, O_WRONLY | O_CREAT | O_APPEND, 0644);
	catch_bad_fd(fd);
	close(fds[pos][1]);
	dup2(fds[pos][0], STDIN_FILENO);
	close(fds[pos][0]);
	dup2(fd, STDOUT_FILENO);
	close(fd);
}
