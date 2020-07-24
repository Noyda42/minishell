/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noyda <noyda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 15:43:14 by temehenn          #+#    #+#             */
/*   Updated: 2020/07/15 12:16:55 by noyda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_env_option(char **arg)
{
	if (!arg[1])
		return (0);
	if (arg[1][0] != '-')
		return (0);
	else if (arg[1][0] == '-' && arg[1][1] != 'i')
		return (-1);
	else
		return (1);
}

static int	get_tmp_env(t_list **env, char **arg)
{
	int		i;
	int		j;
	char	**env_str;

	i = 2;
	j = -1;
	while (arg[++j])
		;
	if (!(env_str = ft_memalloc(j * sizeof(char *) + 1)))
		return (EMALLOC);
	j = 0;
	while (arg[i])
	{
		if (ft_strchr(arg[i], '='))
			env_str[j++] = ft_strdup(arg[i]);
		i++;
	}
	if (env_str && *env_str)
	{
		*env = create_env_list(env_str);
		free_tab(&env_str);
		return (*env == NULL) ? EMALLOC : 0;
	}
	free_tab(&env_str);
	return (0);
}

static char	**get_command(char **arg, int opt, t_list *env, int *ret)
{
	int	i;

	i = opt ? 2 : 1;
	while (arg[i])
	{
		if (!ft_strchr(arg[i], '='))
		{
			if (detect_command(env, &arg[i]) == ECOMMANDNF)
			{
				*ret = ECOMMANDNF;
				return (NULL);
			}
			else
			{
				*ret = 0;
				return (&(arg[i]));
			}
		}
		i++;
	}
	return (NULL);
}

int			exec_ft_env(t_list *active_env, t_list **env, char **arg, int opt)
{
	char	**command;
	int		ret;

	command = NULL;
	ret = 0;
	command = get_command(arg, opt, active_env, &ret);
	if (!command)
		ret = print_env(active_env);
	else if (ret == ECOMMANDNF)
	{
		ft_lstdel(&active_env, free_elem_env_lst);
		return (ret);
	}
	else
		ret = exec_command(&active_env, command);
	if (active_env != *env)
		ft_lstdel(&active_env, free_elem_env_lst);
	return (ret);
}

int			ft_env(t_list **env, char **arg)
{
	t_list	*active_env;
	int		opt;

	active_env = NULL;
	opt = get_env_option(arg);
	if (opt == -1)
		return (EBADOPT);
	else if (opt)
	{
		if (get_tmp_env(&active_env, arg))
			return (EMALLOC);
	}
	else
		active_env = *env;
	return (exec_ft_env(active_env, env, arg, opt));
}
