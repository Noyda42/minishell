/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envlst_to_envtab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noyda <noyda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 18:30:09 by temehenn          #+#    #+#             */
/*   Updated: 2020/07/14 11:05:14 by noyda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**fill_tab(t_list *env, char **new)
{
	t_list	*tmp;
	int		i;
	char	*tmp2;

	tmp = env;
	i = ft_lst_size(env) - 1;
	while (tmp)
	{
		if (!(tmp2 = ft_strjoin(((t_env *)tmp->content)->name, "="))
			|| !(new[i] = ft_strjoin(tmp2, ((t_env *)tmp->content)->content)))
		{
			ft_strdel(&tmp2);
			free(tmp);
			free_tab(&new);
			return (NULL);
		}
		ft_strdel(&tmp2);
		i--;
		tmp = tmp->next;
	}
	return (new);
}

char		**envlst_to_envtab(t_list *env)
{
	char	**new;

	if (!env)
		return (NULL);
	new = NULL;
	if (!(new = ft_memalloc(sizeof(char *) * (ft_lst_size(env) + 1))))
		return (NULL);
	ft_memset((void *)new, 0, sizeof(char *) * (ft_lst_size(env) + 1));
	if (!(new = fill_tab(env, new)))
	{
		free_tab(&new);
		return (NULL);
	}
	return (new);
}
