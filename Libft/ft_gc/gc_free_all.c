/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 19:38:45 by pat               #+#    #+#             */
/*   Updated: 2022/11/22 09:42:04 by tdeville         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../gc.h"
#include "../libft.h"

void	gc_lstclear(t_track **lst, void (*del)(void*))
{
	t_track	*temp;

	if (!lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		gc_lstdelone(lst, del);
		*lst = temp;
	}
}

void	gc_free_all(t_track **track)
{
	gc_lstclear(track, free);
}
