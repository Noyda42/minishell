/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noyda <noyda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:38:23 by temehenn          #+#    #+#             */
/*   Updated: 2020/07/14 11:41:15 by noyda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static size_t		count_word(char const *s, char c)
{
	size_t		size;
	char const	*ps;

	size = 0;
	ps = s;
	while (*ps)
	{
		while (*ps == c)
			ps++;
		if (*ps != c && *ps)
		{
			size++;
			while (*ps != c && *ps)
				ps++;
		}
	}
	return (size);
}

static char			*fill_tab(char const **s, char c, char *tab)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while ((*s)[i] != c && (*s)[i])
		i++;
	if (!(tab = ft_strnew(i)))
		return (NULL);
	while (**s != c && **s)
	{
		tab[j++] = **s;
		(*s)++;
	}
	return (tab);
}

char				**ft_strsplit(char const *s, char c)
{
	size_t		word;
	char		**tab;
	size_t		i;
	char		*tmp;

	i = 0;
	if (!s || !c)
		return (NULL);
	word = count_word(s, c);
	if (!(tab = malloc(sizeof(char *) * (word + 1))))
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			tmp = fill_tab(&s, c, tab[i]);
			if (tmp)
				tab[i++] = tmp;
		}
	}
	if (tab)
		tab[i] = NULL;
	return (tab);
}
