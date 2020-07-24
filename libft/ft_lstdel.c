/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: temehenn <temehenn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:42:52 by temehenn          #+#    #+#             */
/*   Updated: 2019/10/22 17:57:32 by temehenn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *e;

	if (!alst || !del)
		return ;
	while (*alst)
	{
		e = *alst;
		*alst = (*alst)->next;
		ft_lstdelone(&e, del);
	}
}
