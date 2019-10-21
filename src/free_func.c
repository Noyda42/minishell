/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:22:16 by temehenn          #+#    #+#             */
/*   Updated: 2019/10/21 18:26:44 by temehenn         ###   ########.fr       */
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

void	free_elem_env_lst(void *env, size_t size)
{
	t_env *tmp;

	tmp = ((t_list *)env)->content;
	if (!env)
		return ;
	size = sizeof(t_env);
	if (tmp && tmp->name)
		puts(tmp->name);
	if (tmp && tmp->name)
		ft_strdel(&(tmp->name));
	if (tmp->content)
		ft_strdel(&(tmp->content));
}