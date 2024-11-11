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

#endif
