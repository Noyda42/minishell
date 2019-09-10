/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:13:11 by temehenn          #+#    #+#             */
/*   Updated: 2019/09/10 17:36:39 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	builtin[6][10] = {
	{ "echo" },
	{ "cd" },
	{ "env" },
	{ "setenv" },
	{ "unsetenv" },
	{ NULL }
};

static int	is_builtin(char *command)
{
	int	i;

	i = 0;
	while (builtin[i])
	{
		if (!ft_strcmp(command, builtin[i]))
			return (TRUE);
		i++;
	}
	return (FALSE);
}

static int	is_in_binary_path(t_list *env, char *command)
{
	char	**split_path;
	t_list	*bin_paths;
	int		i;

	i = 0;
	split_path = NULL;
	if (!(bin_paths = get_env_content(env, command)))
		return (FALSE);
	if (!(split_path = ft_strsplit(bin_paths, ":")))
		return (FALSE);
	while (split_path[i])
	{
		if (is_in_dir(command, split_path[i] == TRUE))
		{
			free_tab(split_path);
			return (TRUE);
		}
		i++;
	}
	free_tab(split_path);
	return (FALSE);
}

int			detect_command(t_list *env, char *command)
{
	if (!env || !command)
		return (ENULLPARAM);
	if (is_builtin(command) != TRUE
		|| is_in_binary_path(env, command) != TRUE)
		return (ECOMMANDNF);
	return (TRUE);
}
