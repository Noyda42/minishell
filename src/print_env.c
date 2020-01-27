/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 20:18:45 by temehenn          #+#    #+#             */
/*   Updated: 2019/12/02 18:36:17 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	print_env(t_list *env)
{
	t_list	*tmp;

	if (!env)
		return (ENULLPARAM);
	tmp = env;
	if (tmp)
		print_env(tmp->next);
	if (tmp)
	{
		ft_putstr(((t_env*)tmp->content)->name);
		ft_putstr("=");
		ft_putendl(((t_env*)tmp->content)->content);
	}
	return (0);
}