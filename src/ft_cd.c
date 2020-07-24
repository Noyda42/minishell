/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noyda <noyda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 17:27:57 by temehenn          #+#    #+#             */
/*   Updated: 2020/07/15 13:43:12 by noyda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			update_pwd(t_list **env)
{
	char	**tab;

	if (!(tab = (char **)malloc(sizeof(char *) * 4)))
		return (EMALLOC);
	ft_bzero(tab, sizeof(char *) * 4);
	if (!(tab[0] = ft_strdup("setenv"))
		|| !(tab[1] = ft_strdup("PWD"))
		|| !(tab[2] = ft_strnew(8192)))
		return (EMALLOC);
	if (!getcwd(tab[2], 8191))
	{
		free_tab(&tab);
		return (EPATHTL);
	}
	ft_setenv(env, tab);
	free_tab(&tab);
	return (0);
}

static int	update_old_pwd(t_list **env)
{
	char	**tab;
	char	*tmp;

	if (!(tab = (char **)malloc(sizeof(char *) * 4)))
		return (EMALLOC);
	ft_memset(tab, 0, sizeof(char *) * 4);
	if (!(tmp = get_env_content(*env, "PWD")))
	{
		free_tab(&tab);
		return (0);
	}
	if (!(tab[0] = ft_strdup("setenv"))
		|| !(tab[1] = ft_strdup("OLDPWD"))
		|| !(tab[2] = ft_strdup(get_env_content(*env, "PWD"))))
	{
		free_tab(&tab);
		return (EMALLOC);
	}
	ft_setenv(env, tab);
	free_tab(&tab);
	return (0);
}

static int	update_directory(const char *arg)
{
	char	*new_pwd;

	if (!(new_pwd = ft_strnew(8192)))
		return (EMALLOC);
	if (!getcwd(new_pwd, 8191))
	{
		ft_strdel(&new_pwd);
		return (ERPD);
	}
	if (ft_strlen(new_pwd) + ft_strlen(arg) > 8191)
	{
		ft_strdel(&new_pwd);
		return (EPATHTL);
	}
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
	char	*tmp;

	ret = 1;
	tmp = NULL;
	if (!arg[1])
	{
		tmp = get_env_content(*env, "HOME");
		if (!tmp || chdir(tmp))
			return (EHOMENS);
	}
	else if (!ft_strcmp(arg[1], "-"))
	{
		tmp = get_env_content(*env, "OLDPWD");
		if (!tmp || chdir(tmp))
			return (EOLDPWDM);
	}
	else if (arg[1][0] == '/')
	{
		if (chdir(arg[1]))
			return (ECDFAIL);
	}
	else if ((ret = update_directory(arg[1])))
		return (ret);
	return (update_old_pwd(env) || update_pwd(env)) ? EMALLOC : 0;
}
