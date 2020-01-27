/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 15:54:09 by temehenn          #+#    #+#             */
/*   Updated: 2020/01/27 19:55:04 by temehenn         ###   ########.fr       */
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
		free_tab(*av);
		return (EMALLOC);
	}
	return (0);
}

static	char *get_trimmed_command(char *line)
{
	char 	**split;
	int		i;
	char	*result;
	char	*trim;

	i = 0;
	if (!line)
		return (NULL);
	if (ft_strlen(line) == 0)
		return (ft_strdup(""));
	if (!(result = ft_strnew(ft_strlen(line) + 1)))
		return (NULL);
	if (!(split = ft_strsplit(line, '\t')))
		return NULL;
	while (split[i])
	{
		if (!(trim = ft_strtrim(split[i])))
			return (NULL);
		if (ft_strlen(trim)) {
			ft_strcat(result, trim);
			ft_strcat(result, " ");
			ft_strdel(&trim);
		}
		i++;
	}
	free_tab(split);
	return (result);
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
		return (0);
	if ((ret = init_interpreter(&av, &ac, &ret, trim_line)))
		return (ret);
	if ((ret = apply_expansion(*env, &av)))
		return (ret);
	if ((ret = detect_command(*env, &av[0])))
	{
		print_error("Interpreter", av[0]);
		return (ret);
	}
	if ((ret = exec_command(env, av)))
		return (ret);
	free_tab(av);
	free(trim_line);
	return (0);
}