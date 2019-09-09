/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:11:35 by temehenn          #+#    #+#             */
/*   Updated: 2019/09/09 20:56:28 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo(char **tab)
{
	int	index;

	if (!tab)
	{
		print_error("echo", NULL);
		return (ENULLPARAM);
	}
	index = 0;
	while (tab[++index])
		ft_putstr(tab[index]);
	write(1, "\n", 1);
	return (0);
}