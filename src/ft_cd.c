/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 17:27:57 by temehenn          #+#    #+#             */
/*   Updated: 2019/10/16 21:59:00 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	update_pwd(t_list **env)
{
	t_list *tmp;

	tmp = *env;
	while (tmp)
	{
		if (!ft_strcmp("PWD", ((t_env *)tmp->content)->name))
		{
			ft_strdel(&((t_env *)tmp->content)->content);
			if (!(((t_env *)tmp->content)->content = ft_strnew(8192)))
				return (EMALLOC);
			getcwd(((t_env *)tmp->content)->content, 8192);
		}
		tmp = tmp->next;
	}
	return (0);
}

static int	update_old_pwd(t_list **env)
{
	char	**tab;

	if (!(tab = (char **)malloc(sizeof(char *) * 4)))
		return (EMALLOC);
	ft_bzero(tab, sizeof(char *) * 3);
	if (!(tab[0] = ft_strdup("setenv")) || !(tab[1] = ft_strdup("OLDPWD")) || !(tab[2] = ft_strdup(get_env_content(*env, "PWD"))))
		return (EMALLOC);
	ft_setenv(env, tab);
	free_tab(tab);
	return (0);
}

static int	update_directory(t_list **env, const char *arg)
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
	if (update_old_pwd(env))
		return (EMALLOC);
	ft_strdel(&new_pwd);
	return (update_pwd(env));
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
	else if ((ret = update_directory(env, arg[1])))
	 	return (ret);
	else if (ret != 0) 
		if (update_old_pwd(env))
			return(EMALLOC);
	return (0);	
}