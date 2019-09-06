/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 18:38:26 by temehenn          #+#    #+#             */
/*   Updated: 2019/09/05 18:07:21 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

int main(int ac, char **av, char **env)
{
    char    *line;
    int		ret;
	int		_signal;

	_signal = 1;
    line = NULL;
	ret = 0;
    if (ac != 1 || !av)
        ft_putstr_fd("usage: minishell", 2);
    while (_signal)
    {
        write(1, "$>", 2);
        if (get_next_line(0, &line) >= 0)
        {
            if (ret > 0)
            {
                manage_error(ret);
                exit (EXIT_FAILURE);
            }
        }
    }
    return (0);
}