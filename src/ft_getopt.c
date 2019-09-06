/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:35:56 by temehenn          #+#    #+#             */
/*   Updated: 2019/09/06 14:34:38 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static	int	is_endopt(char *str)
{
	return (!ft_strcmp(str, "--")) ? TRUE : FALSE;
}

static	int	is_valid_opt(char *tested_opt, const char *opt_ref, t_option *opt)
{
	int	index;

	index = 1;
	while (tested_opt[index])
	{
		if (!ft_strchr(opt_ref, tested_opt[index]))
		{
			opt->opterr = tested_opt[index];
			return (FALSE);
		}
		index++;
	}
	return (TRUE);
}

static	int malloc_opt(int ac, char **av, const char *opt_ref, t_option *opt)
{
	int	endopt;
	int	size;

	opt->optind = 1;
	endopt = FALSE;
	size = 0;
	while (opt->optind < ac && av[opt->optind] && endopt == FALSE
		&& av[opt->optind][0] == '-' && ft_strlen(av[opt->optind]) > 1)
	{
		if (is_endopt(av[opt->optind]) == TRUE)
			endopt = TRUE;
		else if (is_valid_opt(av[opt->optind], opt_ref, opt) == FALSE)
			return (EINVOPT);
		else
			size++;
		opt->optind++;
	}
	if (!(opt->opt = ft_strnew(size + 1)))
		return (EMALLOC);
	return (0);
}

static void	fill_opt(char **av, t_option *opt)
{
	int	pos;
	int	i;
	int	j;

	pos = 0;
	i = 1;
	while (i < opt->optind)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] != '-' && !ft_strchr(opt->opt, av[i][j]))
				opt->opt[pos++] = av[i][j];
			j++;
		}
		i++;	
	}
}

int			ft_getopt(int ac, char **av, const char *opt_ref, t_option *opt)
{
	int	ret;

	ret = 0;
	if (!av || ac < 1 || !opt_ref)
		return (-1);
	if ((ret = malloc_opt(ac, av, opt_ref, opt)))
		return (ret);
	fill_opt(av, opt);
	return (0);
}