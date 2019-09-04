/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 18:55:27 by temehenn          #+#    #+#             */
/*   Updated: 2019/09/03 20:01:45 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char error_str[128][128] = {
    {"ALL IS OK"},
    {" OLDPWD not set\n"}
};

void    manage_error(int error_code, char *error)
{
    if (error_code < 128)
        ft_putstr_fd(error_str[error_code], 2);
}