/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noyda <noyda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:36:20 by temehenn          #+#    #+#             */
/*   Updated: 2020/07/14 11:09:30 by noyda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <dirent.h>

static int	browse_dir(char *path, char **command, DIR *stream)
{
	struct dirent	*rdir;
	int				i;
	char			*path_command;
	char			*tmp;

	rdir = NULL;
	i = 0;
	while ((rdir = readdir(stream)))
	{
		i++;
		if (!ft_strcmp(rdir->d_name, *command))
		{
			tmp = *command;
			if (!(path_command = ft_strjoin(path, "/")))
				return (EMALLOC);
			if (!(*command = ft_strjoin(path_command, tmp)))
				return (EMALLOC);
			free(tmp);
			free(path_command);
			return (!access(*command, F_OK | X_OK)) ? 0 : EACCES;
		}
	}
	return (i == 0 && !rdir) ? EBADF : ECOMMANDNF;
}

int			is_in_dir(char *path, char **command)
{
	DIR				*stream;
	int				ret;

	stream = NULL;
	ret = 0;
	if (access(path, R_OK))
		return (EACCES);
	if (!(stream = opendir(path)))
		return (EOPNDIR);
	if ((ret = browse_dir(path, command, stream)))
	{
		closedir(stream);
		return (ret);
	}
	closedir(stream);
	return (0);
}
