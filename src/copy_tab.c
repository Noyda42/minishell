/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:42:56 by temehenn          #+#    #+#             */
/*   Updated: 2019/09/06 16:53:24 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**copy_tab(char **tab)
{
	char	**copy;
	int		i;

	copy = NULL;
	i = 0;
	if (!tab)
		return (NULL);
	while (tab[i])
			i++;
	if (!(copy = ft_memalloc(sizeof(char *) * i + 1)))
		return (NULL);
	ft_bzero(copy, sizeof(char *) * i + 1);
	i = -1;
	while (tab[++i])
		if (!(copy[i] = ft_strdup(tab[i])))
			return (NULL);
	return (copy);
}