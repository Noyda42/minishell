/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 17:27:57 by temehenn          #+#    #+#             */
/*   Updated: 2019/10/21 17:57:58 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	update_pwd(t_list **env)
{
	char	**tab;

	if (!(tab = (char **)malloc(sizeof(char *) * 4)))
		return (EMALLOC);
	ft_bzero(tab, sizeof(char *) * 4);
	if (!(tab[0] = ft_strdup("setenv")) || !(tab[1] = ft_strdup("PWD")) || !(tab[2] = ft_strnew(8192)))
		return (EMALLOC);
	if (!getcwd(tab[2], 8191))
	{
		free_tab(tab);
		return (EPATHTL);
	}
	ft_setenv(env, tab);
	free_tab(tab);
	return (0);
}

static int	update_old_pwd(t_list **env)
{
	char	**tab;
	char	*tmp;

	tab = NULL;
	if (!(tab = (char **)malloc(sizeof(char *) * 4)))
		return (EMALLOC);
	if ((tmp = get_env_content(*env, "PWD")))
	{
		if (!(tab[2] = ft_strdup(tmp)))
		{
			free_tab(tab);
			return (EMALLOC);
		}
	}
	else
		return (0);	
	ft_bzero(tab, sizeof(char *) * 4);
	if (!(tab[0] = ft_strdup("setenv")) || !(tab[1] = ft_strdup("OLDPWD")) || !(tab[2] = ft_strdup(get_env_content(*env, "PWD"))))
	{
		free_tab(tab);
		return (EMALLOC);
	}
	ft_setenv(env, tab);
	free_tab(tab);
	return (0);
}

static int	update_directory(const char *arg)
{
	char	*new_pwd;

	if (!(new_pwd = ft_strnew(8192)))
		return (EMALLOC);
	if (!getcwd(new_pwd, 8191))
		return (EPATHTL);
	if (ft_strlen(new_pwd) + ft_strlen(arg) > 8191)
		return (EPATHTL);
	new_pwd = ft_strcat(new_pwd, "/");
	new_pwd = ft_strcat(new_pwd, arg);
	if (chdir(new_pwd))
		return (ECDFAIL);
	ft_strdel(&new_pwd);
	return (0);
}

int			ft_cd(t_list **env, char **arg)
{
	int		ret;

	ret = 1;
	if (!arg[1])
	{
		if (chdir(get_env_content(*env, "HOME")))
			return (EHOMENS);
	}
	else if (!ft_strcmp(arg[1], "-"))
	{
		if (chdir(get_env_content(*env, "OLDPWD")))
			return (EOLDPWDM);
	}
	else if (arg[1][0] == '/')
	{
		if (chdir(arg[1]))
			return (ECDFAIL);
	}
	else if ((ret = update_directory(arg[1])))
	 	return (ret);
	if (update_old_pwd(env) || update_pwd(env))
			return (EMALLOC);
	return (0);	
}