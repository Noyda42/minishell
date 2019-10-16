/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:39:10 by temehenn          #+#    #+#             */
/*   Updated: 2019/10/16 21:34:22 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*find_component(t_list *env, char *env_name)
{
	t_list *tmp;

	tmp = env;
	while (tmp)
	{
		if (!ft_strcmp(env_name, ((t_env *)tmp->content)->name))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

t_list	*add_env_component(t_list **env, char **arg)
{
	t_list *new;

	new = NULL;
	if (!(new = ft_lstnew("", sizeof(t_env))))
		return (EMALLOC);
	if (!(((t_env*)new->content)->name = ft_strdup(arg[1])))
		return (EMALLOC);
	if (!(((t_env*)new->content)->content = ft_strdup(arg[2])))
		return (EMALLOC);
	if (*env)
		ft_lstadd(env, new);
	else
		*env = new;
	return (0);
}

int	setenv(t_list *env, char **arg)
{
	t_list *tmp;
	
	if (arg[1] == NULL)
		return (0);
	if ((tmp = find_component(env, arg[1])))
	{
		ft_strdel(((t_env *)tmp->content)->name);
		if (arg[2])
		{
			if (!(((t_env *)tmp->content)->name = ft_strdup(arg[2])))
				return (EMALLOC);
		}
		else
			if (!(((t_env *)tmp->content)->name = ft_strdup("")))
				return (EMALLOC);
	}
	else
		if ((add_env_component(&env, arg)))
			retrurn (EMALLOC);
	return (0); 
}