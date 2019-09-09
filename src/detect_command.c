/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:13:11 by temehenn          #+#    #+#             */
/*   Updated: 2019/09/09 19:24:27 by temehenn         ###   ########.fr       */
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

static int	is_in_binary_path(char **env, char *command)
{
	if ()
}

int			detect_command(char **env, char *command)
{
	if (!env || !command)
		return (ENULLPARAM);
	if (is_builtin(command) == FALSE
		|| is_in_binary_path(env, command) == FALSE)
		return (ECOMMANDNF);
	return (TRUE);
}
