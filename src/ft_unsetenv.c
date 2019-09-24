/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 19:01:11 by temehenn          #+#    #+#             */
/*   Updated: 2019/09/24 19:24:50 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int	ft_unsetenv(t_list **env, char **arg)
{
	t_list	*tmp;

	tmp = NULL;
	if (!arg[1])
		return (0);
	if ((tmp = find_component(*env, arg[1])))
		ft_lstdelone(&tmp, free_elem_env_lst);
	return (0);
}