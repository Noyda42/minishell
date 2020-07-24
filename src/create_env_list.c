/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noyda <noyda@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:34:02 by temehenn          #+#    #+#             */
/*   Updated: 2020/07/14 11:06:50 by noyda            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	fill_env_list(char *env, t_list **lst)
{
	t_list	*new;
	char	*first_equal;

	new = NULL;
	first_equal = ft_strchr(env, '=') + 1;
	*(first_equal - 1) = 0;
	if (!(new = ft_lstnew("", sizeof(t_env))))
		return (EMALLOC);
	if (!(((t_env*)new->content)->name = ft_strdup(env)))
		return (EMALLOC);
	if (!(((t_env*)new->content)->content = ft_strdup(first_equal)))
		return (EMALLOC);
	if (*lst)
		ft_lstadd(lst, new);
	else
		*lst = new;
	return (0);
}

t_list		*create_env_list(char **env)
{
	t_list	*result;
	int		i;

	result = NULL;
	i = 0;
	while (env[i])
	{
		if ((fill_env_list(env[i], &result)))
		{
			ft_lstdel(&result, free_elem_env_lst);
			return (NULL);
		}
		i++;
	}
	if (!result)
		if (update_pwd(&result))
			return (NULL);
	return (result);
}
