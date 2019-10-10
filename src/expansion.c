/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 11:43:16 by temehenn          #+#    #+#             */
/*   Updated: 2019/10/10 19:36:22 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	tilde_expansion(t_list *env, char **av)
{
	char	*tmp;
	char	*home;

	tmp = *av;
	if (!(home = get_env_content(env, "HOME")))
		return (EHOMENS);
	if (!(*av = ft_strnew(ft_strlen(tmp) + ft_strlen(home) + 1)))
		return (EMALLOC);
	*av = ft_strcpy(*av, home);
	*av = ft_strcat(*av, tmp + 1);
	ft_strdel(&tmp);
	return (0);
}

int			apply_expansion(t_list *env, char ***av)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	while ((*av)[i])
	{
		if (ft_strchr((*av)[i], '$'))
		{
			if ((ret = dollar_expansion(env, &((*av)[i]))))
				return (ret);
		}
		if (((*av)[i][0] == '~' && (*av)[i][1] == '\0')
			|| ((*av)[i][0] == '~' && (*av)[i][1] == '/'))
		{
			if ((ret = tilde_expansion(env, &((*av)[i]))))
				return (ret);
		}
		i++;
	}
	return (0);
}