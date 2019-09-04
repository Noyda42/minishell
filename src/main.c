/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 18:38:26 by temehenn          #+#    #+#             */
/*   Updated: 2019/09/03 19:48:01 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

int main(int ac, char **av)
{
    char    *line;

    line = NULL;
    if (ac != 1 || !av)
        ft_putstr_fd("usage: minishell", 2);
    while (1)
    {
        write(1, "$>", 2);
        if (get_next_line(0, &line) >= 0)
        {
            if (ret > 0)
            {
                manage_error(ret, line);
                exit (EXIT_FAILURE);
            }
        }
    }
    return (0);
}