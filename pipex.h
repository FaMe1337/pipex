/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: famendes <famendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:05:21 by famendes          #+#    #+#             */
/*   Updated: 2024/11/12 19:31:08 by famendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/types.h>
# include <sys/wait.h>
# include <stdlib.h>
# include "Libft/libft.h"

//main
void	child_process(char **av, char **envp, int *fd);
void	parent_process(char **av, char **envp, int *fd);

//utils
void	execute(char *av, char **envp);
char	*find_path(char *cmd, char **envp);
void	error(char *str);
void 	exec_cmd(char **cmd, char **envp);

#endif
