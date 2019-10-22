/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envlst_to_envtab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 18:30:09 by temehenn          #+#    #+#             */
/*   Updated: 2019/10/22 19:01:35 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char **fill_tab(t_list *env, char **new)
{
	t_list	*tmp;
	int		i;
	char	*tmp2;

	tmp = env;
	i = ft_lst_size(env) - 1;
	while (tmp)
	{
		if (!(tmp2 = ft_strjoin(((t_env *)tmp->content)->name, "="))
			||  !(new[i] = ft_strjoin(tmp2, ((t_env *)tmp->content)->content)))
		{
			free(tmp);
			free_tab(new);
			return (NULL);
		}
		i--;
		tmp = tmp->next;
	}
	return (new);
}

char		**envlst_to_envtab(t_list *env)
{
	char	**new;

	new = NULL;
	if (!(new = ft_memalloc(sizeof(char *) * ft_lst_size(env) + 1)))
		return (NULL);
	if (!(new = fill_tab(env, new)))
	{
		free_tab(new);
		return (NULL);
	}
	return (new);
}