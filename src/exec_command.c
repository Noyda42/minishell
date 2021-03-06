/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noyda <noyda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:28:26 by temehenn          #+#    #+#             */
/*   Updated: 2020/07/14 10:38:28 by noyda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/types.h>
#include <sys/wait.h>

static t_builtin	*init_builtin(t_builtin *builtin)
{
	ft_memcpy(builtin[0].name, "echo", 4);
	ft_memcpy(builtin[1].name, "setenv", 6);
	ft_memcpy(builtin[2].name, "unsetenv", 9);
	ft_memcpy(builtin[3].name, "cd", 3);
	ft_memcpy(builtin[4].name, "exit", 5);
	ft_memcpy(builtin[5].name, "env", 4);
	builtin[0].buitlin = ft_echo;
	builtin[1].buitlin = ft_setenv;
	builtin[2].buitlin = ft_unsetenv;
	builtin[3].buitlin = ft_cd;
	builtin[4].buitlin = ft_exit;
	builtin[5].buitlin = ft_env;
	return (builtin);
}

static int			exec_builtin(t_list **env, char **av)
{
	t_builtin	*builtin;
	int			i;
	int			ret;

	i = 0;
	ret = 0;
	if (!(builtin = ft_memalloc(sizeof(t_builtin) * 6)))
		return (EMALLOC);
	ft_bzero(builtin, sizeof(t_builtin) * 6);
	builtin = init_builtin((builtin));
	while (i < 6)
	{
		if (!ft_strcmp(builtin[i].name, av[0]))
		{
			ret = builtin[i].buitlin(env, av);
			break ;
		}
		i++;
	}
	ft_memdel((void **)&builtin);
	return (ret);
}

int					exec_command(t_list **env, char **av)
{
	pid_t	son;
	char	**env_tab;
	int		status;

	status = 1;
	if (!is_builtin(av[0]))
		return (exec_builtin(env, av));
	else
	{
		env_tab = envlst_to_envtab(*env);
		if ((son = fork()) == -1)
			return (EFORKFAIL);
		if (son)
		{
			if (wait(&status) != son)
				return (EWAITFAIL);
			free_tab(&env_tab);
		}
		if (!son)
			execve(av[0], av, env_tab);
	}
	return (0);
}
