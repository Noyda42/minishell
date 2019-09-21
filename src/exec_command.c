/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:28:26 by temehenn          #+#    #+#             */
/*   Updated: 2019/09/21 16:29:22 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_builtin	*init_builtin(t_builtin *builtin)
{
	ft_memcpy(builtin[0].name, "echo", 4);
	builtin[0].buitlin = ft_echo;
	return (builtin);
}

static int exec_builtin(t_list *env, char **av)
{
	t_builtin	*builtin;
	int			i;
	int			ret;

	i = 0;
	ret = 0;
	if (!(builtin = ft_memalloc(sizeof(t_builtin) * 6)))
		return (EMALLOC);
	ft_bzero(builtin, sizeof(t_builtin) * 6);
	builtin = init_builtin((builtin));
	while (i < 6)
	{
		if (!ft_strcmp(builtin[i].name, av[0]))
		{
			ret = builtin[i].buitlin(env, av);
			break ;
		}
	}
	ft_memdel((void **)&builtin);
	return (ret);
}

int	exec_command(t_list *env, char **av)
{
	puts(av[0]);
	if (!is_builtin(av[0]))
		return (exec_builtin(env, av));
	return (ECOMMANDNF);	
}