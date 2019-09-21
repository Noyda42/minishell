/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_expansion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 15:56:39 by temehenn          #+#    #+#             */
/*   Updated: 2019/09/21 16:16:51 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_error_dollar(const char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i] == '$' && !ft_isalnum(av[i + 1]) && av[i + 1] != '\0')
			return (EDOLLEXP);
		i++;
	}
	return (0);
}

static int	substitute_var(t_list *env, char **av, char **split)
{
	int		i;
	char	*value;
	char	*tmp;

	value = NULL;
	i = (**av == '$') ? 0 : 1;
	while (split[i])
	{
		tmp = split[i];
		if ((value = get_env_content(env, split[i])))
		{
			if (!(split[i] = ft_strdup(value)))
				return (EMALLOC);
		}
		else
			split[i] = ft_strdup("");
		ft_strdel(&tmp);
		i++;
	}
	return (0);
}

static int	fill_substitute(char **av, char **split)
{
	int		i;
	int		size;
	char	*tmp;

	i = 0;
	size = 0;
	tmp = *av;
	while (split[i])
		size += ft_strlen(split[i++]);
	if (!(*av = ft_strnew(size + 1)))
		return (EMALLOC);
	ft_strdel(&tmp);
	i = 0;
	while (split[i])
		*av = ft_strcat(*av, split[i++]);
	return (0);
}

int			dollar_expansion(t_list *env, char **av)
{
	int		ret;
	char	**split;

	split = NULL;
	ret = 0;
	if ((ret = check_error_dollar(*av)))
		return (ret);
	if (!(split = ft_strsplit(*av, '$')))
		return (EMALLOC);
	if ((ret = substitute_var(env, av, split)))
	{
		free_tab(split);
		return (ret);
	}
	if ((ret = fill_substitute(av, split)))
	{
		free_tab(split);
		return (ret);
	}
	return (0);
}