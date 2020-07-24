/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noyda <noyda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 15:54:09 by temehenn          #+#    #+#             */
/*   Updated: 2020/07/14 11:35:39 by noyda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	init_interpreter(char ***av, int *ac, int *ret, char *line)
{
	*ret = 0;
	*ac = 0;
	*av = 0;
	if (!line)
		return (ENULLPARAM);
	if (!(*av = ft_strsplit(line, ' ')))
	{
		free_tab(av);
		return (EMALLOC);
	}
	return (0);
}

static int	delete_white_spaces(char **result, char **split)
{
	char	*trim;
	int		i;

	trim = NULL;
	i = 0;
	while (split[i])
	{
		if (!(trim = ft_strtrim(split[i])))
		{
			ft_strdel(result);
			free_tab(&split);
			return (EMALLOC);
		}
		if (ft_strlen(trim))
		{
			*result = ft_strcat(*result, trim);
			*result = ft_strcat(*result, " ");
		}
		ft_strdel(&trim);
		i++;
	}
	if (trim)
		ft_strdel(&trim);
	return (0);
}

static char	*get_trimmed_command(char *line)
{
	char	**split;
	char	*result;

	split = NULL;
	if (!line)
		return (NULL);
	if (ft_strlen(line) == 0)
		return (ft_strdup(""));
	if (!(result = ft_strnew(ft_strlen(line) + 1)))
		return (NULL);
	if (!(split = ft_strsplit(line, '\t')))
	{
		ft_strdel(&result);
		return (NULL);
	}
	if (delete_white_spaces(&result, split) == EMALLOC)
		return (NULL);
	free_tab(&split);
	return (result);
}

static int	f_e(char *trim_line, char **av, int flag)
{
	ft_strdel(&trim_line);
	if (flag == 1)
		print_error("Interpreter", av[0]);
	free_tab(&av);
	return (0);
}

int			interpreter(t_list **env, char *line)
{
	char	**av;
	int		ret;
	int		ac;
	char	*trim_line;

	if (!(trim_line = get_trimmed_command(line)))
		return (EMALLOC);
	if (!ft_strcmp(trim_line, "") || !ft_strcmp(trim_line, " "))
	{
		ft_strdel(&trim_line);
		return (0);
	}
	if ((ret = init_interpreter(&av, &ac, &ret, trim_line))
		&& !f_e(trim_line, av, 0))
		return (ret);
	if ((ret = apply_expansion(*env, &av)) && !f_e(trim_line, av, 0))
		return (ret);
	if ((ret = detect_command(*env, &av[0])) && !f_e(trim_line, av, 0))
		return (ret);
	if ((ret = exec_command(env, av)) > 0 && !f_e(trim_line, av, 0))
		return (ret);
	free_tab(&av);
	ft_strdel(&trim_line);
	return (ret);
}
