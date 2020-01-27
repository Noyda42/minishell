/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 15:43:14 by temehenn          #+#    #+#             */
/*   Updated: 2020/01/27 18:26:22 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


static int get_env_option(char **arg)
{
	if (!arg[1])
		return (0);
	if (arg[1][0] != '-')
		return (0);
	else if (arg[1][0] == '-' && arg[1][1] != 'i')
		return (EBADOPT);
	else
		return (1);
}

static int	get_tmp_env(t_list **env, char **arg)
{
	int		i;
	int		j;
	char	**env_str;

	i = 2;
	j = 0;
	while (arg[j])
		j++;
	if (!(env_str = ft_memalloc(j * sizeof(char *) + 1)))
		return (EMALLOC);
	j = 0;
	while (arg[i])
	{
		if (ft_strchr(arg[i], '='))
			env_str[j++] = ft_strdup(arg[i]);
		i++;
	}
	*env = create_env_list(env_str);
	free(env_str);
	return (env) ? 0 : (EMALLOC);
}

static char **get_command(char **arg, int opt, t_list *env, int *ret)
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
				return NULL;
			}
			else
				return (&(arg[i]));
		}
		i++;
	}
	return NULL;
}

int			ft_env(t_list **env, char **arg)
{
	t_list	*active_env;
	char	**command;
	int		opt;
	int		ret;

	active_env = NULL;
	command = NULL;
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
	command = get_command(arg, opt, active_env, &ret);
	if (!command) {
		ret = print_env(active_env);
	}
	else if (ret == ECOMMANDNF) {
		return ret;
	}
	else
		ret = exec_command(&active_env, command);
	return (ret);
}