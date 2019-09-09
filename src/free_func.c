/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:22:16 by temehenn          #+#    #+#             */
/*   Updated: 2019/09/09 20:54:25 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_tab(char **tab)
{
	int	i;

	i = -1;
	if (!tab)
		return ;
	while (tab[++i])
		ft_memdel((void **)&tab[i]);
	tab = NULL;
}

void	*free_elem_env_lst(t_env *env, size_t size)
{
	if (!env)
		return (NULL);
	size = sizeof(t_env);
	ft_strdel(&env->content);
	ft_strdel(&env->name);
	ft_memdel((void**)&env);
	env = NULL;
	return (env);
}