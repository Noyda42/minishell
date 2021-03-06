/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noyda <noyda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:13:11 by temehenn          #+#    #+#             */
/*   Updated: 2020/07/14 11:13:51 by noyda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	g_builtin[8][10] = {
	{ "echo" },
	{ "cd" },
	{ "env" },
	{ "setenv" },
	{ "unsetenv" },
	{ "exit" },
	{ "env" },
	{ 0 }
};

int			is_builtin(char *command)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		if (!ft_strcmp(command, g_builtin[i]))
			return (0);
		i++;
	}
	return (ECOMMANDNF);
}

static int	is_in_binary_path(t_list *env, char **command)
{
	char	**split_path;
	char	*bin_paths;
	int		i;

	i = 0;
	split_path = NULL;
	if (!(bin_paths = get_env_content(env, "PATH")))
		return (ECOMMANDNF);
	if (!(split_path = ft_strsplit(bin_paths, ':')))
		return (EMALLOC);
	while (split_path[i])
	{
		if (is_in_dir(split_path[i], command) == 0)
		{
			free_tab(&split_path);
			return (0);
		}
		i++;
	}
	free_tab(&split_path);
	return (ECOMMANDNF);
}

int			detect_command(t_list *env, char **command)
{
	int	ret;

	ret = 0;
	if (!command || (command && !(*command)))
		return (ENULLPARAM);
	if (!(ret = is_builtin(*command)) && ret != ECOMMANDNF)
		return (ret);
	else if (!access(*command, F_OK | X_OK))
		return (0);
	else if ((ret = is_in_binary_path(env, command)) && ret != ECOMMANDNF)
		return (ret);
	return (ret);
}
