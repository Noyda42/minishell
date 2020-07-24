/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noyda <noyda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 18:55:27 by temehenn          #+#    #+#             */
/*   Updated: 2020/07/15 13:06:27 by noyda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	g_error_str[128][128] = {
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
	{"$ expansion : syntax error.\n"},
	{"cd expansion: path too long\n"},
	{"cd expansion: can't access to this directory.\n"},
	{"Fork fail.\n"},
	{"Wait fail.\n"},
	{"Bad option.\n"},
	{"Can't retrieve parent's directory.\n"},
};

void		manage_error(int error_code)
{
	if (error_code < 128)
		ft_putstr_fd(g_error_str[error_code], 2);
}
