/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 15:54:09 by temehenn          #+#    #+#             */
/*   Updated: 2019/10/10 19:17:10 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	init_interpreter(char ***av, int *ac, int *ret, char *line)
{
	*ret = 0;
	*ac = 0;
	*av = 0;
	if (!line)
		return (ENULLPARAM);
	if (!(*av = ft_strsplit(line, ' ')))
	{
		free_tab(*av);
		return (EMALLOC);
	}
	return (0);
}

int			interpreter(t_list **env, char *line)
{
	char	**av; //free
	int		ret;
	int		ac;

	// print_env(env);
	if (!ft_strcmp(line, ""))
		return (0);
	if ((ret = init_interpreter(&av, &ac, &ret, line)))
		return (ret);
	if ((ret = apply_expansion(*env, &av)))
		return (ret);
	if ((ret = detect_command(*env, &av[0])))
	{
		print_error("Interpreter", av[0]);
		return (ret);
	}
	if ((ret = exec_command(env, av)))
		return (ret);
	free_tab(av);
	return (0);
}