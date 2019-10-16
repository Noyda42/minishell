/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 17:27:57 by temehenn          #+#    #+#             */
/*   Updated: 2019/10/16 21:06:20 by temehenn         ###   ########.fr       */
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
			ft_putendl(((t_env *)tmp->content)->content);
		}
		tmp = tmp->next;
	}
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
	ft_strdel(&new_pwd);
	return (update_pwd(env));
}

int			ft_cd(t_list **env, char **arg)
{
	int		ret;

	ret = 0;
	if (!arg[1])
	{
		if (chdir(get_env_content(*env, "HOME")))
			return (EHOMENS);
		else
			return (0);		
	}
	if (arg[1][0] == '/')
	{
		if (chdir(arg[1]))
			return (ECDFAIL);
		else
			return (0);		
	}
	 if ((ret = update_directory(env, arg[1])))
	 	return (ret);
	return (0);
}