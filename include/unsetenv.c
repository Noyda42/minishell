/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 19:01:11 by temehenn          #+#    #+#             */
/*   Updated: 2019/09/24 19:05:16 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int	ft_unsetenv(t_list **env, char **arg)
{
	t_list	*tmp;

	tmp = NULL;
	if (!arg[1])
		return (0);
	if ((tmp = find_component(env, arg[1])))
		free_elem_env_lst(tmp, sizeof(t_env));
	return (0);
}