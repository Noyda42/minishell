/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 15:54:09 by temehenn          #+#    #+#             */
/*   Updated: 2019/09/10 17:15:32 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	init_interpreter(char ***av, int *ac, int *ret, char *line)
{
	*ret = 0;
	*ac = 0;
	*av = 0;
	if (!(av = ft_strsplit(line, ' ')))
	{
		free_tab(av);
		return (EMALLOC);
	}
	return (0);
}

int			interpreter(t_list *env, char *line)
{
	char	**av; //free
	int		ret;
	int		ac;

	if (!env || !line)
		return (ENULLPARAM);
	if ((ret = init_interpreter(&av, &ac, &ret, line)))
		return(ret);
	if ((ret = detect_command(env, av[0])))
	{
		print_error("Interpreter", av[0]);
		return (ret);
	}
	return (1);
}