/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famendes <famendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:15:56 by famendes          #+#    #+#             */
/*   Updated: 2024/11/04 16:54:18 by famendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (ac == 5)
	{
		
	}
	else
		ft_putstr_fd("Wrong arguments, please struc like the following example: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 2);
	return (0);
}
