/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famendes <famendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:57:10 by famendes          #+#    #+#             */
/*   Updated: 2024/11/11 15:11:18 by famendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void free_paths(char **paths)
{
	int i = 0;
	while (paths[i])
		free(paths[i++]);
	free(paths);
}

void	error(char *str)
{
	perror(str);
	exit(1);
}

char	*find_path(char *cmd, char **envp)
{
	int		i;
	char	**paths;
	char	*result;
	char	*path;

	i = 0;
	while (ft_strncmp(envp[i], "PATH", 4) != 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		path = ft_strjoin(paths[i], "/");
		result = ft_strjoin(path, cmd);
		free(path);
		if (access(result, F_OK) == 0)
		{
			free_paths(paths);
			return (result);
		}
		free(result);
		i++;
	}
	free_paths(paths);
	return (NULL);
}

void	execute(char *av, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(av, ' ');
	path = find_path(cmd[0], envp);
	if (!path)
	{
		free_paths(cmd);
		error("Path not found");
	}
	if (execve(path, cmd, envp) == -1)
	{
		free_paths(cmd);
		free(path);
		error("Execve failed");
	}

}
