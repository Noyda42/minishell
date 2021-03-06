/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noyda <noyda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 19:01:11 by temehenn          #+#    #+#             */
/*   Updated: 2020/07/14 11:12:14 by noyda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	remove_link(t_list **env, char *arg)
{
	t_list *prev;
	t_list *current;

	prev = *env;
	current = NULL;
	while (prev->next)
	{
		current = prev->next;
		if (!ft_strcmp(((t_env *)current->content)->name, arg))
		{
			prev->next = current->next;
			free_elem_env_lst(current->content, sizeof(t_env));
			free(current);
			return ;
		}
		prev = prev->next;
	}
}

int			ft_unsetenv(t_list **env, char **arg)
{
	t_list	*prev;

	if (!env || !(*env) || !arg[1])
		return (0);
	prev = *env;
	if (!ft_strcmp(((t_env *)prev->content)->name, arg[1]))
	{
		*env = (*env)->next;
		free_elem_env_lst(prev->content, sizeof(t_env));
		free(prev);
		return (0);
	}
	else if ((*env)->next)
		remove_link(env, arg[1]);
	return (0);
}
