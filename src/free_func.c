/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noyda <noyda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:22:16 by temehenn          #+#    #+#             */
/*   Updated: 2020/07/14 11:10:28 by noyda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_tab(char ***tab_addr)
{
	char	**tab;
	int		i;

	i = 0;
	tab = NULL;
	if (tab_addr)
		tab = *tab_addr;
	if (!tab)
		return ;
	while (tab[i])
	{
		ft_strdel(&(tab[i]));
		i++;
	}
	if (tab)
		free(tab);
	*tab_addr = NULL;
	tab = NULL;
}

void	free_elem_env_lst(void *env, size_t size)
{
	if (!env)
		return ;
	(void)size;
	if (((t_env *)env)->name)
		ft_strdel(&(((t_env *)env)->name));
	if (((t_env *)env)->content)
		ft_strdel(&(((t_env *)env)->content));
	ft_memdel(&env);
	env = NULL;
}
