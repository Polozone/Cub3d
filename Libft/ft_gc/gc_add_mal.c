/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_add_mal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeville <tdeville@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:52:46 by pat               #+#    #+#             */
/*   Updated: 2022/11/22 09:42:04 by tdeville         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../gc.h"
#include "../libft.h"

void	gc_add_mal(t_track **track, void **address)
{
	if (!(*track))
		*track = gc_lstnew(address);
	else
		gc_lstadd_front(track, gc_lstnew(address));
}
