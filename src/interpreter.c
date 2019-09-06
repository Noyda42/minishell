/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 15:54:09 by temehenn          #+#    #+#             */
/*   Updated: 2019/09/06 16:35:47 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_tabs(char **env_cp, char **av)
{
	free_tab(env_cp);
	free_tab(av);
}

int			interpreter(char **env, char *line)
{
	char	**av; //free
	int		ac;
	char	**env_cp; //free

	if (!env || !line)
		return (ENULLPARAM);
	if (!(env_cp = copy_tab(env)) || !(av = ft_strsplit(line, " ")))
	{
		free_tabs(env_cp, av);
		return (EMALLOC);
	}
	if (detect_command(env, av[0]) == FALSE)
	{
		return (ECOMNF);
	}
}