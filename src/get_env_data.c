/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:18:18 by temehenn          #+#    #+#             */
/*   Updated: 2019/09/17 17:35:43 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env_content(t_list *env, char *env_name)
{
	t_list *tmp;

	tmp = env;
	if (!env || !env_name)
		return (NULL);
	while (tmp)
	{
		if (!ft_strcmp(env_name, ((t_env *)tmp->content)->name))
			return (((t_env *)tmp->content)->content);
		tmp = tmp->next;
	}
	return (NULL);
}