/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noyda <noyda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:25:38 by temehenn          #+#    #+#             */
/*   Updated: 2020/07/14 11:39:07 by noyda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_error(char *func_name, char *error_cause)
{
	if (func_name)
	{
		ft_putstr_fd(func_name, 2);
		ft_putstr_fd(": ", 2);
	}
	if (!error_cause)
		return ;
	else
	{
		ft_putstr_fd(error_cause, 2);
		ft_putstr_fd(": ", 2);
	}
}
