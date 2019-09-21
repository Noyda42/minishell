/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:11:35 by temehenn          #+#    #+#             */
/*   Updated: 2019/09/21 11:34:45 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo(t_list *env, char **arg)
{
	int	index;

	(void)env;
	if (!arg)
	{
		print_error("echo", NULL);
		return (ENULLPARAM);
	}
	index = 0;
	while (arg[++index])
	{
		ft_putstr(arg[index]);
		ft_putstr(" ");
	}
	write(1, "\n", 1);
	return (0);
}