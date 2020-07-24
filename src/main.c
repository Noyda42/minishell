/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noyda <noyda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 18:38:26 by temehenn          #+#    #+#             */
/*   Updated: 2020/07/14 10:46:48 by noyda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

static int	minishell(char **env)
{
	char	*line;
	int		ret;
	t_list	*env_list;

	line = NULL;
	ret = 0;
	env_list = (env) ? create_env_list(env) : NULL;
	while (1)
	{
		write(1, "$>", 2);
		if ((ret = get_next_line(0, &line) >= 0))
		{
			if ((ret = interpreter(&env_list, line)) > 0)
				manage_error(ret);
			ft_strdel(&line);
			if (ret == EXIT)
				break ;
		}
		else if (ret < 0)
			manage_error(ret);
	}
	return (0);
}

int			main(int ac, char **av, char **env)
{
	int	ret;

	ret = 0;
	if (ac != 1 || !av)
		ft_putstr_fd("usage: minishell", 2);
	if ((ret = minishell(env)))
		manage_error(ret);
	return (0);
}
