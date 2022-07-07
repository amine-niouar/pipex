/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniouar <aniouar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:19:27 by aniouar           #+#    #+#             */
/*   Updated: 2022/07/06 04:36:08 by aniouar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include "pipex.h"

typedef struct s_herdoc
{
	int		status;
	char	*tempo;
}	t_herdoc;

typedef struct s_cmd
{
	char			**options;
	char			*correct_path;
	struct s_cmd	*next;
	struct s_cmd	*previous;
	int				herdoc;
}	t_cmd;

typedef struct s_bash
{
	t_cmd		*cmd;
	t_herdoc	*herdoc;
	char		**env;
}	t_bash;

void	close_except(int ***cfds, int len_cmd, int except);
t_cmd	*fill_cmds(int ac, char **av, char **env, int range);
int		len_cmds(t_cmd *cmd);
void	link_nodes(t_cmd **previous, t_cmd **current);
void	fill_current(t_cmd **current, char *cmd, char **path_env);
void	multi_pipes(t_bash *bash, char **av, int ***fds);
int		**pipe_feach_proc(int len);
void	close_except_me(int ***cfds, int len_cmd, int except);
char	*get_next_line(int fd);
void	heredoc_check(int ac, char **av, t_bash **bash);
void	herdoc_main(char **av, t_bash **bash);
void	first_proc(int ***cfds, int pos, char *infile);
void	medium_proc(int ***cfds, int pos);
void	last_proc(int ***cfds, int pos, char *outfile, int mod);
#endif
