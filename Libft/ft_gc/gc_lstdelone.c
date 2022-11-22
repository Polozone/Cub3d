/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:55:57 by pat               #+#    #+#             */
/*   Updated: 2022/11/22 09:49:43 by tdeville         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../gc.h"
#include "../libft.h"

void	gc_lstdelone(t_track **lst, void (*del)(void*))
{
	if (*lst)
	{
		if ((*lst)->address)
		{
			del((*lst)->address);
			(*lst)->address = NULL;
			(*lst)->next = NULL;
			free(*lst);
			*lst = NULL;
		}
	}
}
