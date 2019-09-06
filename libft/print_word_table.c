/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_word_table.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 17:45:13 by temehenn          #+#    #+#             */
/*   Updated: 2019/09/05 17:47:28 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_word_table(char **tab)
{
	int		i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
		ft_putendl(tab[i++]);
}