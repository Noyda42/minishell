/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noyda <noyda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:01:05 by temehenn          #+#    #+#             */
/*   Updated: 2020/07/14 11:10:46 by noyda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_exit(t_list **env, char **arg)
{
	(void)arg;
	ft_lstdel(env, free_elem_env_lst);
	return (EXIT);
}
