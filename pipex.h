/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aniouar <aniouar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:40:43 by aniouar           #+#    #+#             */
/*   Updated: 2022/07/07 09:12:40 by aniouar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <string.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

char	**ft_split(char *s, char c);
size_t	ft_strlen(const char *s);
char	*ft_strdup(char *s);
int		ft_strpos(const char *s, int c);
char	*ft_strdup(char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
void	*ft_bzero(void *s, size_t n);
char	*ft_strcat(char *dest, char *src);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strjoin(char *s1, char *s2, int mod);
char	*ft_substr(char *s, unsigned int start, size_t len, int mod);
void	ft_putstr_endl(int fd, char *s);
char	**get_path_env(char **env);
int		len_of_arrays(char **srcs);
int		get_total_len(char **paths);
int		max_len_tab(char **strs);
char	*get_correct_path(char **paths, char *cmd);
char	*get_path_from_env(char **env, char *env_name);
void	catch_bad_fd(int fd);
int		outfile_handle(int fd, char *outfile);
void	fchild_proc(char *infile, char *fcmd, char ***array_env, int *fds);
void	schild_proc(char *outfile, char *secmd, char ***array_env, int *fds);
void	parent_proc(int *fds, int fid, int sid);
int		append(char **full_path, char *path, char *cmd, int len_path);
int		infile_path(char *cmd);
void	cmd_nfound(void);
void	memory_error(void);
void	check_empty(char *cmd);
void	custom_error(char *s, int mod);
int		check_pass_path(char *cmd);
char	***fill_array_env(char **env);
void	regular_pipe(char **av, char ***array_env);
void	cmd_errror(char *correct_path);
#endif
