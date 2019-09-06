/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 18:38:26 by temehenn          #+#    #+#             */
/*   Updated: 2019/09/06 16:54:00 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

static int	minishell(int ac, char **av, char **env)
{
	char    *line;
    int		ret;
	char	**cp_env;

    line = NULL;
	ret = 0;
	if (!(cp_env = copy_tab(env)))
		return (EMALLOC);
	ac = 2;
	av = 0;
    // while (1)
    // {
    //     write(1, "$>", 2);
    //     if (get_next_line(0, &line) >= 0)
    //     {
    //         if ((ret = interpreter(env, line)) > 0)
    //             manage_error(ret);
	// 		ft_memdel(&line);
    //     }
    // }
	print_word_table(cp_env);
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