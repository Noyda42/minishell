/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:01:05 by temehenn          #+#    #+#             */
/*   Updated: 2019/10/22 18:48:08 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_exit(t_list **env, char **arg)
{
	ft_lstdel(env, free_elem_env_lst);
	if (arg)
		free_tab(arg);
	exit(0);
	return (0);
}