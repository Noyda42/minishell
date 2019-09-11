/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 17:36:20 by temehenn          #+#    #+#             */
/*   Updated: 2019/09/11 18:31:22 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <dirent.h>

int	is_in_dir(char *path, char *command)
{
	DIR				*stream;
	struct dirent	*rdir;

	stream = NULL;
	if (!access(path, R_OK))
		return (EACCES);
	if (!(stream = opendir(path)))
		return (EOPNDIR);
	if (!(rdir = readdir(stream)))
		return (EBADF);
}