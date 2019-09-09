/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 18:38:26 by temehenn          #+#    #+#             */
/*   Updated: 2019/09/09 20:42:32 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

static int	minishell(int ac, char **av, char **env)
{
	char    *line;
    int		ret;
	t_list	*env_list;

    line = NULL;
	ret = 0;
	ac = 2;
	av = 0;
	if (!(env_list = create_env_list(env)))
		return (EMALLOC);
    // while (1)
    // {
    //     write(1, "$>", 2);
    //     if ((ret = get_next_line(0, &line) >= 0))
    //     {
    //         if ((ret = interpreter(env, line)) > 0)
    //             manage_error(ret);
	// 		ft_memdel(&line);
	// 	}
	// 	else if (ret < 0)
    //             manage_error(ret);
    // }
	print_env(env_list);
	return (0);
}

int main(int ac, char **av, char **env)
{
	int	ret;

	ret = 0;
	if (ac != 1 || !av)
        ft_putstr_fd("usage: minishell", 2);
	if ((ret = minishell(ac, av, env)))
		manage_error(ret);
    return (0);
}