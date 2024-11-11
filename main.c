/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famendes <famendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:15:56 by famendes          #+#    #+#             */
/*   Updated: 2024/11/11 17:22:31 by famendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(char **av, char **envp, int *fd)
{
	int	filein;

	close(fd[0]);
	filein = open(av[1], O_RDONLY);
	if (filein < 0)
	{
		close(fd[1]);
		error("Failed opening filein");
	}
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	dup2(filein, STDIN_FILENO);
	close(filein);
	execute(av[2], envp);
}

void	parent_process(char **av, char **envp, int *fd)
{
	int	fileout;

	close(fd[1]);
	fileout = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fileout < 0)
	{
		close(fd[0]);
		error("Failed opening fileout");
	}
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	dup2(fileout, STDOUT_FILENO);
	close(fileout);
	execute(av[3], envp);
}

int	main(int ac, char **av, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (ac == 5)
	{
		if (av[2][0] == 0 || av[3][0] == 0)
			error("cmd is empty");
		if (!envp[0])
			error("Envp path doesnt exist");
		if (pipe(fd) < 0)
			error("pipe creation failed");
		pid = fork();
		if (pid == -1)
			error("creation of forked failed");
		else if (pid == 0)
		{
			child_process(av, envp, fd);
			waitpid(pid, NULL, 0);
		}
		parent_process(av, envp, fd);
	}
	else
		ft_putstr_fd("Wrong arguments, please struc like the following example: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 2);
	return (0);
}
