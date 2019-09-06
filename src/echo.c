/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:11:35 by temehenn          #+#    #+#             */
/*   Updated: 2019/09/05 18:47:22 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo(char *str)
{
	char	*opt;
	int		ret;

	opt = NULL;
	if ((ret = ft_getopt(str, ECHO_OPT, &opt)))
		return (ret);
}
