/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 18:55:27 by temehenn          #+#    #+#             */
/*   Updated: 2019/09/21 15:28:16 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char error_str[128][128] = {
    {"ALL IS OK"},
    {"OLDPWD not set\n"},
    {"Failed to malloc.\n"},
    {"Invalid option.\n"},
    {"NULL param is given as argument.\n"},
    {"Command not found.\n"},
    {"An error occurs in get_next_line.\n"},
    {"Permission denied.\n"},
    {"Can't open this dir.\n"},
    {"Bad stream descriptor.\n"},
    {"Home is not set.\n"},
    {"$ expansion : syntax error.\n"}
};

void    manage_error(int error_code)
{
    if (error_code < 128)
        ft_putstr_fd(error_str[error_code], 2);
}