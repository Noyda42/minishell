/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_builtin_name_error.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:25:38 by temehenn          #+#    #+#             */
/*   Updated: 2019/09/05 18:32:27 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_builtin_error(char *builtin_name, char *error_cause)
{
	if (builtin_name)
	{
		ft_putstr_fd(builtin_name, 2);
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